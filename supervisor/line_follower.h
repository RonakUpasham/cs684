/* --- Generated the 11/4/2024 at 19:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#include "line_follower_types.h"
#include "mc_ext.h"
typedef struct Line_follower__calculatePID_mem {
  float v_4;
  int v_3;
  float v_1;
  int v;
} Line_follower__calculatePID_mem;

typedef struct Line_follower__calculatePID_out {
  float pidValue;
} Line_follower__calculatePID_out;

void Line_follower__calculatePID_reset(Line_follower__calculatePID_mem* self);

void Line_follower__calculatePID_step(float error,
                                      Line_follower__calculatePID_out* _out,
                                      Line_follower__calculatePID_mem* self);

typedef struct Line_follower__calculateError_out {
  float error;
} Line_follower__calculateError_out;

void Line_follower__calculateError_step(float sen[5], float weights[4],
                                        Line_follower__calculateError_out* _out);

typedef struct Line_follower__calculateMotor1_mem {
  Line_follower__st ck;
  int pnr;
  int diR_2;
  int vr_2;
  int vl_2;
} Line_follower__calculateMotor1_mem;

typedef struct Line_follower__calculateMotor1_out {
  int v_l;
  int v_r;
  int dir;
} Line_follower__calculateMotor1_out;

void Line_follower__calculateMotor1_reset(Line_follower__calculateMotor1_mem* self);

void Line_follower__calculateMotor1_step(float pidValue,
                                         Line_follower__calculateMotor1_out* _out,
                                         Line_follower__calculateMotor1_mem* self);

typedef struct Line_follower__calculateMotor2_mem {
  Line_follower__st_1 ck;
  int pnr;
  int diR_3;
  int vr_3;
  int vl_3;
} Line_follower__calculateMotor2_mem;

typedef struct Line_follower__calculateMotor2_out {
  int v_l;
  int v_r;
  int dir;
} Line_follower__calculateMotor2_out;

void Line_follower__calculateMotor2_reset(Line_follower__calculateMotor2_mem* self);

void Line_follower__calculateMotor2_step(float sen[5], float pidValue,
                                         int count, int flag,
                                         Line_follower__calculateMotor2_out* _out,
                                         Line_follower__calculateMotor2_mem* self);

typedef struct Line_follower__counter_mem {
  Line_follower__st_2 ck;
  int pnr;
  int beaconcount_1;
  int flg_1;
  int cnt_2;
} Line_follower__counter_mem;

typedef struct Line_follower__counter_out {
  int count;
  int flag;
} Line_follower__counter_out;

void Line_follower__counter_reset(Line_follower__counter_mem* self);

void Line_follower__counter_step(float sen[5], int beacon, int second,
                                 Line_follower__counter_out* _out,
                                 Line_follower__counter_mem* self);

typedef struct Line_follower__check_out {
  int white_switch;
  int black_switch;
} Line_follower__check_out;

void Line_follower__check_step(float sen[5], int second,
                               Line_follower__check_out* _out);

typedef struct Line_follower__main_mem {
  Line_follower__st_3 ck;
  int pnr;
  Line_follower__calculateMotor1_mem calculateMotor1;
  Line_follower__calculateMotor2_mem calculateMotor2;
  Line_follower__calculatePID_mem calculatePID;
  Line_follower__counter_mem counter;
} Line_follower__main_mem;

typedef struct Line_follower__main_out {
  int v_l;
  int v_r;
  int dir;
  int cnt;
  float pidValue;
} Line_follower__main_out;

void Line_follower__main_reset(Line_follower__main_mem* self);

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, int second, int beacon,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self);

#endif // LINE_FOLLOWER_H
