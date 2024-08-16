/* --- Generated the 11/4/2024 at 19:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts park.ept --- */

#ifndef PARK_H
#define PARK_H

#include "park_types.h"
#include "mc_ext.h"
typedef struct Park__calculatePID_mem {
  float v_4;
  int v_3;
  float v_1;
  int v;
} Park__calculatePID_mem;

typedef struct Park__calculatePID_out {
  float pidValue;
} Park__calculatePID_out;

void Park__calculatePID_reset(Park__calculatePID_mem* self);

void Park__calculatePID_step(float error, Park__calculatePID_out* _out,
                             Park__calculatePID_mem* self);

typedef struct Park__calculateError_out {
  float error;
} Park__calculateError_out;

void Park__calculateError_step(float sen[5], Park__calculateError_out* _out);

typedef struct Park__parking_mem {
  int v_28;
  int v_26;
  int v_23;
  int v_21;
  int v_38;
  int v_36;
  int v_33;
  int v_31;
  Park__st ck;
  int pnr;
} Park__parking_mem;

typedef struct Park__parking_out {
  int v_l;
  int v_r;
  int dir;
} Park__parking_out;

void Park__parking_reset(Park__parking_mem* self);

void Park__parking_step(int beacon, int diR, Park__parking_out* _out,
                        Park__parking_mem* self);

typedef struct Park__calculateMotor3_mem {
  Park__st_1 ck;
  int v_59;
  int v_57;
  int v_54;
  int v_52;
  int pnr;
  int diR_3;
  int vr_1;
  int vl_1;
  Park__parking_mem parking;
  Park__parking_mem parking_1;
} Park__calculateMotor3_mem;

typedef struct Park__calculateMotor3_out {
  int v_l;
  int v_r;
  int dir;
} Park__calculateMotor3_out;

void Park__calculateMotor3_reset(Park__calculateMotor3_mem* self);

void Park__calculateMotor3_step(int irSen1, int irSen2, int irSen3,
                                int irSen4, float pidValue, int beacon,
                                Park__calculateMotor3_out* _out,
                                Park__calculateMotor3_mem* self);

typedef struct Park__main_mem {
  Park__calculateMotor3_mem calculateMotor3;
  Park__calculatePID_mem calculatePID;
} Park__main_mem;

typedef struct Park__main_out {
  int v_l;
  int v_r;
  int dir;
} Park__main_out;

void Park__main_reset(Park__main_mem* self);

void Park__main_step(int sen0, int sen1, int sen2, int sen3, int sen4,
                     int irSen1, int irSen2, int irSen3, int irSen4,
                     int beacon, Park__main_out* _out, Park__main_mem* self);

#endif // PARK_H
