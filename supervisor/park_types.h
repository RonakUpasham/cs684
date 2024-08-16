/* --- Generated the 11/4/2024 at 19:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts park.ept --- */

#ifndef PARK_TYPES_H
#define PARK_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
#include "mc_ext_types.h"
typedef enum {
  Park__St_1_Turn,
  Park__St_1_Parking2,
  Park__St_1_Parking1,
  Park__St_1_Forward
} Park__st_1;

Park__st_1 Park__st_1_of_string(char* s);

char* string_of_Park__st_1(Park__st_1 x, char* buf);

typedef enum {
  Park__St_Turn,
  Park__St_Stationary,
  Park__St_Forward
} Park__st;

Park__st Park__st_of_string(char* s);

char* string_of_Park__st(Park__st x, char* buf);

static const float Park__kp = 0.300000;

static const float Park__kd = 0.300000;

static const float Park__ki = 0.000000;

static const float Park__weights[4] = {0.350000, 0.280000, 0.405000, 0.350000};

#endif // PARK_TYPES_H
