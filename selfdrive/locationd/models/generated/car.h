#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_1673219004331321340);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7685300362947227633);
void car_H_mod_fun(double *state, double *out_7906035710387220062);
void car_f_fun(double *state, double dt, double *out_4520596976096901018);
void car_F_fun(double *state, double dt, double *out_3330787842923361570);
void car_h_25(double *state, double *unused, double *out_2485841073551241221);
void car_H_25(double *state, double *unused, double *out_5566715376639757475);
void car_h_24(double *state, double *unused, double *out_9107689886717443190);
void car_H_24(double *state, double *unused, double *out_3651963511000598916);
void car_h_30(double *state, double *unused, double *out_2210647011266735332);
void car_H_30(double *state, double *unused, double *out_1039019046512149277);
void car_h_26(double *state, double *unused, double *out_3131220224619295231);
void car_H_26(double *state, double *unused, double *out_1825212057765701251);
void car_h_27(double *state, double *unused, double *out_8884882590965090367);
void car_H_27(double *state, double *unused, double *out_3262613117696092494);
void car_h_29(double *state, double *unused, double *out_5247433062711068017);
void car_H_29(double *state, double *unused, double *out_1549250390826541461);
void car_h_28(double *state, double *unused, double *out_88573126699093227);
void car_H_28(double *state, double *unused, double *out_3533148626242989113);
void car_h_31(double *state, double *unused, double *out_6010819607712498771);
void car_H_31(double *state, double *unused, double *out_1199003955532349775);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}