#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_8821442694437018176);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_2669404392972591154);
void gnss_H_mod_fun(double *state, double *out_3628383119241527248);
void gnss_f_fun(double *state, double dt, double *out_2911894030962606432);
void gnss_F_fun(double *state, double dt, double *out_8657587500259786555);
void gnss_h_6(double *state, double *sat_pos, double *out_1940478305202382078);
void gnss_H_6(double *state, double *sat_pos, double *out_5861605845652759501);
void gnss_h_20(double *state, double *sat_pos, double *out_3198189178613923928);
void gnss_H_20(double *state, double *sat_pos, double *out_3468662543713286228);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2083846631906470419);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_227112697527214299);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2083846631906470419);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_227112697527214299);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}