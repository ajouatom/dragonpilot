#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.11.1                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7319293501589091026) {
   out_7319293501589091026[0] = delta_x[0] + nom_x[0];
   out_7319293501589091026[1] = delta_x[1] + nom_x[1];
   out_7319293501589091026[2] = delta_x[2] + nom_x[2];
   out_7319293501589091026[3] = delta_x[3] + nom_x[3];
   out_7319293501589091026[4] = delta_x[4] + nom_x[4];
   out_7319293501589091026[5] = delta_x[5] + nom_x[5];
   out_7319293501589091026[6] = delta_x[6] + nom_x[6];
   out_7319293501589091026[7] = delta_x[7] + nom_x[7];
   out_7319293501589091026[8] = delta_x[8] + nom_x[8];
   out_7319293501589091026[9] = delta_x[9] + nom_x[9];
   out_7319293501589091026[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4162741171589677059) {
   out_4162741171589677059[0] = -nom_x[0] + true_x[0];
   out_4162741171589677059[1] = -nom_x[1] + true_x[1];
   out_4162741171589677059[2] = -nom_x[2] + true_x[2];
   out_4162741171589677059[3] = -nom_x[3] + true_x[3];
   out_4162741171589677059[4] = -nom_x[4] + true_x[4];
   out_4162741171589677059[5] = -nom_x[5] + true_x[5];
   out_4162741171589677059[6] = -nom_x[6] + true_x[6];
   out_4162741171589677059[7] = -nom_x[7] + true_x[7];
   out_4162741171589677059[8] = -nom_x[8] + true_x[8];
   out_4162741171589677059[9] = -nom_x[9] + true_x[9];
   out_4162741171589677059[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_8461055172459071962) {
   out_8461055172459071962[0] = 1.0;
   out_8461055172459071962[1] = 0;
   out_8461055172459071962[2] = 0;
   out_8461055172459071962[3] = 0;
   out_8461055172459071962[4] = 0;
   out_8461055172459071962[5] = 0;
   out_8461055172459071962[6] = 0;
   out_8461055172459071962[7] = 0;
   out_8461055172459071962[8] = 0;
   out_8461055172459071962[9] = 0;
   out_8461055172459071962[10] = 0;
   out_8461055172459071962[11] = 0;
   out_8461055172459071962[12] = 1.0;
   out_8461055172459071962[13] = 0;
   out_8461055172459071962[14] = 0;
   out_8461055172459071962[15] = 0;
   out_8461055172459071962[16] = 0;
   out_8461055172459071962[17] = 0;
   out_8461055172459071962[18] = 0;
   out_8461055172459071962[19] = 0;
   out_8461055172459071962[20] = 0;
   out_8461055172459071962[21] = 0;
   out_8461055172459071962[22] = 0;
   out_8461055172459071962[23] = 0;
   out_8461055172459071962[24] = 1.0;
   out_8461055172459071962[25] = 0;
   out_8461055172459071962[26] = 0;
   out_8461055172459071962[27] = 0;
   out_8461055172459071962[28] = 0;
   out_8461055172459071962[29] = 0;
   out_8461055172459071962[30] = 0;
   out_8461055172459071962[31] = 0;
   out_8461055172459071962[32] = 0;
   out_8461055172459071962[33] = 0;
   out_8461055172459071962[34] = 0;
   out_8461055172459071962[35] = 0;
   out_8461055172459071962[36] = 1.0;
   out_8461055172459071962[37] = 0;
   out_8461055172459071962[38] = 0;
   out_8461055172459071962[39] = 0;
   out_8461055172459071962[40] = 0;
   out_8461055172459071962[41] = 0;
   out_8461055172459071962[42] = 0;
   out_8461055172459071962[43] = 0;
   out_8461055172459071962[44] = 0;
   out_8461055172459071962[45] = 0;
   out_8461055172459071962[46] = 0;
   out_8461055172459071962[47] = 0;
   out_8461055172459071962[48] = 1.0;
   out_8461055172459071962[49] = 0;
   out_8461055172459071962[50] = 0;
   out_8461055172459071962[51] = 0;
   out_8461055172459071962[52] = 0;
   out_8461055172459071962[53] = 0;
   out_8461055172459071962[54] = 0;
   out_8461055172459071962[55] = 0;
   out_8461055172459071962[56] = 0;
   out_8461055172459071962[57] = 0;
   out_8461055172459071962[58] = 0;
   out_8461055172459071962[59] = 0;
   out_8461055172459071962[60] = 1.0;
   out_8461055172459071962[61] = 0;
   out_8461055172459071962[62] = 0;
   out_8461055172459071962[63] = 0;
   out_8461055172459071962[64] = 0;
   out_8461055172459071962[65] = 0;
   out_8461055172459071962[66] = 0;
   out_8461055172459071962[67] = 0;
   out_8461055172459071962[68] = 0;
   out_8461055172459071962[69] = 0;
   out_8461055172459071962[70] = 0;
   out_8461055172459071962[71] = 0;
   out_8461055172459071962[72] = 1.0;
   out_8461055172459071962[73] = 0;
   out_8461055172459071962[74] = 0;
   out_8461055172459071962[75] = 0;
   out_8461055172459071962[76] = 0;
   out_8461055172459071962[77] = 0;
   out_8461055172459071962[78] = 0;
   out_8461055172459071962[79] = 0;
   out_8461055172459071962[80] = 0;
   out_8461055172459071962[81] = 0;
   out_8461055172459071962[82] = 0;
   out_8461055172459071962[83] = 0;
   out_8461055172459071962[84] = 1.0;
   out_8461055172459071962[85] = 0;
   out_8461055172459071962[86] = 0;
   out_8461055172459071962[87] = 0;
   out_8461055172459071962[88] = 0;
   out_8461055172459071962[89] = 0;
   out_8461055172459071962[90] = 0;
   out_8461055172459071962[91] = 0;
   out_8461055172459071962[92] = 0;
   out_8461055172459071962[93] = 0;
   out_8461055172459071962[94] = 0;
   out_8461055172459071962[95] = 0;
   out_8461055172459071962[96] = 1.0;
   out_8461055172459071962[97] = 0;
   out_8461055172459071962[98] = 0;
   out_8461055172459071962[99] = 0;
   out_8461055172459071962[100] = 0;
   out_8461055172459071962[101] = 0;
   out_8461055172459071962[102] = 0;
   out_8461055172459071962[103] = 0;
   out_8461055172459071962[104] = 0;
   out_8461055172459071962[105] = 0;
   out_8461055172459071962[106] = 0;
   out_8461055172459071962[107] = 0;
   out_8461055172459071962[108] = 1.0;
   out_8461055172459071962[109] = 0;
   out_8461055172459071962[110] = 0;
   out_8461055172459071962[111] = 0;
   out_8461055172459071962[112] = 0;
   out_8461055172459071962[113] = 0;
   out_8461055172459071962[114] = 0;
   out_8461055172459071962[115] = 0;
   out_8461055172459071962[116] = 0;
   out_8461055172459071962[117] = 0;
   out_8461055172459071962[118] = 0;
   out_8461055172459071962[119] = 0;
   out_8461055172459071962[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_731843756774827001) {
   out_731843756774827001[0] = dt*state[3] + state[0];
   out_731843756774827001[1] = dt*state[4] + state[1];
   out_731843756774827001[2] = dt*state[5] + state[2];
   out_731843756774827001[3] = state[3];
   out_731843756774827001[4] = state[4];
   out_731843756774827001[5] = state[5];
   out_731843756774827001[6] = dt*state[7] + state[6];
   out_731843756774827001[7] = dt*state[8] + state[7];
   out_731843756774827001[8] = state[8];
   out_731843756774827001[9] = state[9];
   out_731843756774827001[10] = state[10];
}
void F_fun(double *state, double dt, double *out_6240084532272754259) {
   out_6240084532272754259[0] = 1;
   out_6240084532272754259[1] = 0;
   out_6240084532272754259[2] = 0;
   out_6240084532272754259[3] = dt;
   out_6240084532272754259[4] = 0;
   out_6240084532272754259[5] = 0;
   out_6240084532272754259[6] = 0;
   out_6240084532272754259[7] = 0;
   out_6240084532272754259[8] = 0;
   out_6240084532272754259[9] = 0;
   out_6240084532272754259[10] = 0;
   out_6240084532272754259[11] = 0;
   out_6240084532272754259[12] = 1;
   out_6240084532272754259[13] = 0;
   out_6240084532272754259[14] = 0;
   out_6240084532272754259[15] = dt;
   out_6240084532272754259[16] = 0;
   out_6240084532272754259[17] = 0;
   out_6240084532272754259[18] = 0;
   out_6240084532272754259[19] = 0;
   out_6240084532272754259[20] = 0;
   out_6240084532272754259[21] = 0;
   out_6240084532272754259[22] = 0;
   out_6240084532272754259[23] = 0;
   out_6240084532272754259[24] = 1;
   out_6240084532272754259[25] = 0;
   out_6240084532272754259[26] = 0;
   out_6240084532272754259[27] = dt;
   out_6240084532272754259[28] = 0;
   out_6240084532272754259[29] = 0;
   out_6240084532272754259[30] = 0;
   out_6240084532272754259[31] = 0;
   out_6240084532272754259[32] = 0;
   out_6240084532272754259[33] = 0;
   out_6240084532272754259[34] = 0;
   out_6240084532272754259[35] = 0;
   out_6240084532272754259[36] = 1;
   out_6240084532272754259[37] = 0;
   out_6240084532272754259[38] = 0;
   out_6240084532272754259[39] = 0;
   out_6240084532272754259[40] = 0;
   out_6240084532272754259[41] = 0;
   out_6240084532272754259[42] = 0;
   out_6240084532272754259[43] = 0;
   out_6240084532272754259[44] = 0;
   out_6240084532272754259[45] = 0;
   out_6240084532272754259[46] = 0;
   out_6240084532272754259[47] = 0;
   out_6240084532272754259[48] = 1;
   out_6240084532272754259[49] = 0;
   out_6240084532272754259[50] = 0;
   out_6240084532272754259[51] = 0;
   out_6240084532272754259[52] = 0;
   out_6240084532272754259[53] = 0;
   out_6240084532272754259[54] = 0;
   out_6240084532272754259[55] = 0;
   out_6240084532272754259[56] = 0;
   out_6240084532272754259[57] = 0;
   out_6240084532272754259[58] = 0;
   out_6240084532272754259[59] = 0;
   out_6240084532272754259[60] = 1;
   out_6240084532272754259[61] = 0;
   out_6240084532272754259[62] = 0;
   out_6240084532272754259[63] = 0;
   out_6240084532272754259[64] = 0;
   out_6240084532272754259[65] = 0;
   out_6240084532272754259[66] = 0;
   out_6240084532272754259[67] = 0;
   out_6240084532272754259[68] = 0;
   out_6240084532272754259[69] = 0;
   out_6240084532272754259[70] = 0;
   out_6240084532272754259[71] = 0;
   out_6240084532272754259[72] = 1;
   out_6240084532272754259[73] = dt;
   out_6240084532272754259[74] = 0;
   out_6240084532272754259[75] = 0;
   out_6240084532272754259[76] = 0;
   out_6240084532272754259[77] = 0;
   out_6240084532272754259[78] = 0;
   out_6240084532272754259[79] = 0;
   out_6240084532272754259[80] = 0;
   out_6240084532272754259[81] = 0;
   out_6240084532272754259[82] = 0;
   out_6240084532272754259[83] = 0;
   out_6240084532272754259[84] = 1;
   out_6240084532272754259[85] = dt;
   out_6240084532272754259[86] = 0;
   out_6240084532272754259[87] = 0;
   out_6240084532272754259[88] = 0;
   out_6240084532272754259[89] = 0;
   out_6240084532272754259[90] = 0;
   out_6240084532272754259[91] = 0;
   out_6240084532272754259[92] = 0;
   out_6240084532272754259[93] = 0;
   out_6240084532272754259[94] = 0;
   out_6240084532272754259[95] = 0;
   out_6240084532272754259[96] = 1;
   out_6240084532272754259[97] = 0;
   out_6240084532272754259[98] = 0;
   out_6240084532272754259[99] = 0;
   out_6240084532272754259[100] = 0;
   out_6240084532272754259[101] = 0;
   out_6240084532272754259[102] = 0;
   out_6240084532272754259[103] = 0;
   out_6240084532272754259[104] = 0;
   out_6240084532272754259[105] = 0;
   out_6240084532272754259[106] = 0;
   out_6240084532272754259[107] = 0;
   out_6240084532272754259[108] = 1;
   out_6240084532272754259[109] = 0;
   out_6240084532272754259[110] = 0;
   out_6240084532272754259[111] = 0;
   out_6240084532272754259[112] = 0;
   out_6240084532272754259[113] = 0;
   out_6240084532272754259[114] = 0;
   out_6240084532272754259[115] = 0;
   out_6240084532272754259[116] = 0;
   out_6240084532272754259[117] = 0;
   out_6240084532272754259[118] = 0;
   out_6240084532272754259[119] = 0;
   out_6240084532272754259[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_3816338357172882771) {
   out_3816338357172882771[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_5766712616144609008) {
   out_5766712616144609008[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5766712616144609008[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5766712616144609008[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_5766712616144609008[3] = 0;
   out_5766712616144609008[4] = 0;
   out_5766712616144609008[5] = 0;
   out_5766712616144609008[6] = 1;
   out_5766712616144609008[7] = 0;
   out_5766712616144609008[8] = 0;
   out_5766712616144609008[9] = 0;
   out_5766712616144609008[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_3691888153521146197) {
   out_3691888153521146197[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_3697786557749810575) {
   out_3697786557749810575[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3697786557749810575[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3697786557749810575[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_3697786557749810575[3] = 0;
   out_3697786557749810575[4] = 0;
   out_3697786557749810575[5] = 0;
   out_3697786557749810575[6] = 1;
   out_3697786557749810575[7] = 0;
   out_3697786557749810575[8] = 0;
   out_3697786557749810575[9] = 1;
   out_3697786557749810575[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_4150799050302153836) {
   out_4150799050302153836[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_6034825300366711760) {
   out_6034825300366711760[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[6] = 0;
   out_6034825300366711760[7] = 1;
   out_6034825300366711760[8] = 0;
   out_6034825300366711760[9] = 0;
   out_6034825300366711760[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_4150799050302153836) {
   out_4150799050302153836[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_6034825300366711760) {
   out_6034825300366711760[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_6034825300366711760[6] = 0;
   out_6034825300366711760[7] = 1;
   out_6034825300366711760[8] = 0;
   out_6034825300366711760[9] = 0;
   out_6034825300366711760[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_7319293501589091026) {
  err_fun(nom_x, delta_x, out_7319293501589091026);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_4162741171589677059) {
  inv_err_fun(nom_x, true_x, out_4162741171589677059);
}
void gnss_H_mod_fun(double *state, double *out_8461055172459071962) {
  H_mod_fun(state, out_8461055172459071962);
}
void gnss_f_fun(double *state, double dt, double *out_731843756774827001) {
  f_fun(state,  dt, out_731843756774827001);
}
void gnss_F_fun(double *state, double dt, double *out_6240084532272754259) {
  F_fun(state,  dt, out_6240084532272754259);
}
void gnss_h_6(double *state, double *sat_pos, double *out_3816338357172882771) {
  h_6(state, sat_pos, out_3816338357172882771);
}
void gnss_H_6(double *state, double *sat_pos, double *out_5766712616144609008) {
  H_6(state, sat_pos, out_5766712616144609008);
}
void gnss_h_20(double *state, double *sat_pos, double *out_3691888153521146197) {
  h_20(state, sat_pos, out_3691888153521146197);
}
void gnss_H_20(double *state, double *sat_pos, double *out_3697786557749810575) {
  H_20(state, sat_pos, out_3697786557749810575);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_4150799050302153836) {
  h_7(state, sat_pos_vel, out_4150799050302153836);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_6034825300366711760) {
  H_7(state, sat_pos_vel, out_6034825300366711760);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_4150799050302153836) {
  h_21(state, sat_pos_vel, out_4150799050302153836);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_6034825300366711760) {
  H_21(state, sat_pos_vel, out_6034825300366711760);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
