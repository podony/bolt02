import os

from cereal import car
from common.params import Params
from system.hardware import PC, TICI, EON
from selfdrive.manager.process import PythonProcess, NativeProcess, DaemonProcess

NO_IR_CTRL = os.path.isfile('/data/media/0/no_ir_ctrl')
log_on = os.path.isfile('/data/media/0/log_on')

WEBCAM = os.getenv("USE_WEBCAM") is not None

def driverview(started: bool, params: Params, CP: car.CarParams) -> bool:
  return params.get_bool("IsDriverViewEnabled")  # type: ignore

def notcar(started: bool, params: Params, CP: car.CarParams) -> bool:
  return CP.notCar  # type: ignore

def logging(started, params, CP: car.CarParams) -> bool:
  run = (not CP.notCar) or not params.get_bool("DisableLogging")
  return started and run

def ublox_available() -> bool:
  if EON:
    return True
  return os.path.exists('/dev/ttyHS0') and not os.path.exists('/persist/comma/use-quectel-gps')

def ublox(started, params, CP: car.CarParams) -> bool:
  use_ublox = ublox_available()
  params.put_bool("UbloxAvailable", use_ublox)
  return started and use_ublox

def qcomgps(started, params, CP: car.CarParams) -> bool:
  return started and not ublox_available()

procs = [
  # due to qualcomm kernel bugs SIGKILLing camerad sometimes causes page table corruption
  NativeProcess("camerad", "selfdrive/camerad", ["./camerad"], unkillable=True, callback=driverview),
  NativeProcess("clocksd", "system/clocksd", ["./clocksd"]),
  NativeProcess("logcatd", "system/logcatd", ["./logcatd"], enabled=log_on),
  NativeProcess("proclogd", "system/proclogd", ["./proclogd"], enabled=log_on),
  PythonProcess("logmessaged", "system.logmessaged", offroad=True, enabled=log_on),
  # PythonProcess("micd", "system.micd"),
  # PythonProcess("timezoned", "system.timezoned", enabled=not PC, offroad=True),

  DaemonProcess("manage_athenad", "selfdrive.athena.manage_athenad", "AthenadPid"),
  NativeProcess("dmonitoringmodeld", "selfdrive/legacy_modeld", ["./dmonitoringmodeld"], enabled=(not PC or WEBCAM) and not NO_IR_CTRL, callback=driverview),
  # NativeProcess("encoderd", "system/loggerd", ["./encoderd"]),
  NativeProcess("loggerd", "selfdrive/loggerd", ["./loggerd"], onroad=False, callback=logging, enabled=log_on),
  NativeProcess("modeld", "selfdrive/legacy_modeld", ["./modeld"]),
  # NativeProcess("mapsd", "selfdrive/navd", ["./map_renderer"], enabled=False),
  # NativeProcess("navmodeld", "selfdrive/modeld", ["./navmodeld"], enabled=False),
  NativeProcess("sensord", "system/sensord", ["./sensord"], enabled=not PC, offroad=True),
  NativeProcess("ui", "selfdrive/ui", ["./ui"], offroad=True, watchdog_max_dt=(5 if not PC else None)),
  NativeProcess("soundd", "selfdrive/ui/soundd", ["./soundd"], offroad=True),
  NativeProcess("locationd", "selfdrive/locationd", ["./locationd"]),
  NativeProcess("boardd", "selfdrive/boardd", ["./boardd"], enabled=False),
  PythonProcess("calibrationd", "selfdrive.locationd.calibrationd"),
  PythonProcess("torqued", "selfdrive.locationd.torqued"),
  PythonProcess("controlsd", "selfdrive.controls.controlsd"),
  PythonProcess("deleter", "selfdrive.loggerd.deleter", offroad=True, enabled=log_on),
  PythonProcess("dmonitoringd", "selfdrive.legacy_monitoring.dmonitoringd", enabled=(not PC or WEBCAM) and not NO_IR_CTRL, callback=driverview),
  # PythonProcess("laikad", "selfdrive.locationd.laikad"),
  # PythonProcess("rawgpsd", "system.sensord.rawgps.rawgpsd", enabled=TICI, onroad=False, callback=qcomgps),
  # PythonProcess("navd", "selfdrive.navd.navd"),
  PythonProcess("pandad", "selfdrive.boardd.pandad", offroad=True),
  PythonProcess("paramsd", "selfdrive.locationd.paramsd"),
  NativeProcess("ubloxd", "system/ubloxd", ["./ubloxd"], enabled=not PC, onroad=False, callback=ublox),
  # PythonProcess("pigeond", "system.sensord.pigeond", enabled=TICI, onroad=False, callback=ublox),
  PythonProcess("plannerd", "selfdrive.controls.plannerd"),
  PythonProcess("radard", "selfdrive.controls.radard"),
  PythonProcess("thermald", "selfdrive.thermald.thermald", offroad=True),
  PythonProcess("tombstoned", "selfdrive.tombstoned", enabled=not PC, offroad=True),
  PythonProcess("updated", "selfdrive.updated", enabled=not PC, onroad=False, offroad=True),
  # PythonProcess("uploader", "selfdrive.loggerd.uploader", offroad=True),
  # PythonProcess("statsd", "selfdrive.statsd", offroad=True),

  # debug procs
  NativeProcess("bridge", "cereal/messaging", ["./bridge"], onroad=False, callback=notcar),
  PythonProcess("webjoystick", "tools.joystick.web", onroad=False, callback=notcar),

  # EON only
  PythonProcess("rtshield", "selfdrive.rtshield", enabled=EON),
  PythonProcess("shutdownd", "system.hardware.eon.shutdownd", enabled=EON),
  PythonProcess("androidd", "system.hardware.eon.androidd", enabled=EON, offroad=True),

  # mapd
  PythonProcess("mapd", "selfdrive.dragonpilot.mapd"),
  # gpxd
  PythonProcess("gpxd", "selfdrive.dragonpilot.gpxd"),
  PythonProcess("gpx_uploader", "selfdrive.dragonpilot.gpx_uploader", offroad=True),
]

managed_processes = {p.name: p for p in procs}
