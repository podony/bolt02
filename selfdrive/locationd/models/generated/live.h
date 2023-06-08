#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_7160508158065063740);
void live_err_fun(double *nom_x, double *delta_x, double *out_9119248387773333404);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_6697903320192654180);
void live_H_mod_fun(double *state, double *out_277792456163775303);
void live_f_fun(double *state, double dt, double *out_4978833357093498698);
void live_F_fun(double *state, double dt, double *out_6849203160499840969);
void live_h_4(double *state, double *unused, double *out_416461024327247384);
void live_H_4(double *state, double *unused, double *out_3921598954962045660);
void live_h_9(double *state, double *unused, double *out_8227592735492858479);
void live_H_9(double *state, double *unused, double *out_3365619980302401810);
void live_h_10(double *state, double *unused, double *out_4296550159527316506);
void live_H_10(double *state, double *unused, double *out_4607961823255245423);
void live_h_12(double *state, double *unused, double *out_7070759218890925604);
void live_H_12(double *state, double *unused, double *out_1097857453069916135);
void live_h_35(double *state, double *unused, double *out_5090403797667048641);
void live_H_35(double *state, double *unused, double *out_554936897589438284);
void live_h_32(double *state, double *unused, double *out_6688851263345634384);
void live_H_32(double *state, double *unused, double *out_6154347310456520517);
void live_h_13(double *state, double *unused, double *out_4001286955811606869);
void live_H_13(double *state, double *unused, double *out_9160093207497218410);
void live_h_14(double *state, double *unused, double *out_8227592735492858479);
void live_H_14(double *state, double *unused, double *out_3365619980302401810);
void live_h_33(double *state, double *unused, double *out_3464094948502741824);
void live_H_33(double *state, double *unused, double *out_2595620107049419320);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}