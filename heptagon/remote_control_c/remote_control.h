/* --- Generated the 17/4/2024 at 15:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts remote_control.ept --- */

#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include "remote_control_types.h"
typedef struct Remote_control__manual_control_mem {
  Remote_control__st ck;
  int pnr;
} Remote_control__manual_control_mem;

typedef struct Remote_control__manual_control_out {
  int v_l;
  int v_r;
  int dir;
} Remote_control__manual_control_out;

void Remote_control__manual_control_reset(Remote_control__manual_control_mem* self);

void Remote_control__manual_control_step(int diR,
                                         Remote_control__manual_control_out* _out,
                                         Remote_control__manual_control_mem* self);

typedef struct Remote_control__main_mem {
  Remote_control__st_1 ck;
  int pnr;
  Remote_control__manual_control_mem manual_control;
} Remote_control__main_mem;

typedef struct Remote_control__main_out {
  int v_l;
  int v_r;
  int dir;
} Remote_control__main_out;

void Remote_control__main_reset(Remote_control__main_mem* self);

void Remote_control__main_step(int diR, Remote_control__main_out* _out,
                               Remote_control__main_mem* self);

#endif // REMOTE_CONTROL_H
