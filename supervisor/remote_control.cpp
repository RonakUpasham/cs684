/* --- Generated the 17/4/2024 at 15:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts remote_control.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "remote_control.h"

void Remote_control__manual_control_reset(Remote_control__manual_control_mem* self) {
  self->pnr = false;
  self->ck = Remote_control__St_Idle;
}

void Remote_control__manual_control_step(int diR,
                                         Remote_control__manual_control_out* _out,
                                         Remote_control__manual_control_mem* self) {
  
  int v_6;
  Remote_control__st v_5;
  int v_4;
  Remote_control__st v_3;
  int v_2;
  int v_1;
  int v;
  int v_13;
  Remote_control__st v_12;
  int v_11;
  Remote_control__st v_10;
  int v_9;
  int v_8;
  int v_7;
  int v_20;
  Remote_control__st v_19;
  int v_18;
  Remote_control__st v_17;
  int v_16;
  int v_15;
  int v_14;
  int v_27;
  Remote_control__st v_26;
  int v_25;
  Remote_control__st v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_37;
  Remote_control__st v_36;
  int v_35;
  Remote_control__st v_34;
  int v_33;
  Remote_control__st v_32;
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int r_St_Down;
  Remote_control__st s_St_Down;
  int r_St_Left;
  Remote_control__st s_St_Left;
  int r_St_Right;
  Remote_control__st s_St_Right;
  int r_St_Up;
  Remote_control__st s_St_Up;
  int r_St_Idle;
  Remote_control__st s_St_Idle;
  int nr_St_Down;
  Remote_control__st ns_St_Down;
  int dir_St_Down;
  int v_r_St_Down;
  int v_l_St_Down;
  int nr_St_Left;
  Remote_control__st ns_St_Left;
  int dir_St_Left;
  int v_r_St_Left;
  int v_l_St_Left;
  int nr_St_Right;
  Remote_control__st ns_St_Right;
  int dir_St_Right;
  int v_r_St_Right;
  int v_l_St_Right;
  int nr_St_Up;
  Remote_control__st ns_St_Up;
  int dir_St_Up;
  int v_r_St_Up;
  int v_l_St_Up;
  int nr_St_Idle;
  Remote_control__st ns_St_Idle;
  int dir_St_Idle;
  int v_r_St_Idle;
  int v_l_St_Idle;
  Remote_control__st ck_1;
  Remote_control__st s;
  Remote_control__st ns;
  int r;
  int nr;
  switch (self->ck) {
    case Remote_control__St_Idle:
      v_31 = (diR==3);
      if (v_31) {
        v_33 = true;
        v_32 = Remote_control__St_Up;
      } else {
        v_33 = self->pnr;
        v_32 = Remote_control__St_Idle;
      };
      v_30 = (diR==4);
      if (v_30) {
        v_35 = true;
        v_34 = Remote_control__St_Down;
      } else {
        v_35 = v_33;
        v_34 = v_32;
      };
      v_29 = (diR==1);
      if (v_29) {
        v_37 = true;
        v_36 = Remote_control__St_Left;
      } else {
        v_37 = v_35;
        v_36 = v_34;
      };
      v_28 = (diR==2);
      if (v_28) {
        r_St_Idle = true;
        s_St_Idle = Remote_control__St_Right;
      } else {
        r_St_Idle = v_37;
        s_St_Idle = v_36;
      };
      s = s_St_Idle;
      r = r_St_Idle;
      break;
    case Remote_control__St_Up:
      v_23 = (diR==4);
      if (v_23) {
        v_25 = true;
        v_24 = Remote_control__St_Down;
      } else {
        v_25 = self->pnr;
        v_24 = Remote_control__St_Up;
      };
      v_22 = (diR==1);
      if (v_22) {
        v_27 = true;
        v_26 = Remote_control__St_Left;
      } else {
        v_27 = v_25;
        v_26 = v_24;
      };
      v_21 = (diR==2);
      if (v_21) {
        r_St_Up = true;
        s_St_Up = Remote_control__St_Right;
      } else {
        r_St_Up = v_27;
        s_St_Up = v_26;
      };
      s = s_St_Up;
      r = r_St_Up;
      break;
    case Remote_control__St_Right:
      v_16 = (diR==4);
      if (v_16) {
        v_18 = true;
        v_17 = Remote_control__St_Down;
      } else {
        v_18 = self->pnr;
        v_17 = Remote_control__St_Right;
      };
      v_15 = (diR==1);
      if (v_15) {
        v_20 = true;
        v_19 = Remote_control__St_Left;
      } else {
        v_20 = v_18;
        v_19 = v_17;
      };
      v_14 = (diR==3);
      if (v_14) {
        r_St_Right = true;
        s_St_Right = Remote_control__St_Up;
      } else {
        r_St_Right = v_20;
        s_St_Right = v_19;
      };
      s = s_St_Right;
      r = r_St_Right;
      break;
    case Remote_control__St_Left:
      v_9 = (diR==4);
      if (v_9) {
        v_11 = true;
        v_10 = Remote_control__St_Down;
      } else {
        v_11 = self->pnr;
        v_10 = Remote_control__St_Left;
      };
      v_8 = (diR==2);
      if (v_8) {
        v_13 = true;
        v_12 = Remote_control__St_Right;
      } else {
        v_13 = v_11;
        v_12 = v_10;
      };
      v_7 = (diR==3);
      if (v_7) {
        r_St_Left = true;
        s_St_Left = Remote_control__St_Up;
      } else {
        r_St_Left = v_13;
        s_St_Left = v_12;
      };
      s = s_St_Left;
      r = r_St_Left;
      break;
    case Remote_control__St_Down:
      v_2 = (diR==1);
      if (v_2) {
        v_4 = true;
        v_3 = Remote_control__St_Left;
      } else {
        v_4 = self->pnr;
        v_3 = Remote_control__St_Down;
      };
      v_1 = (diR==2);
      if (v_1) {
        v_6 = true;
        v_5 = Remote_control__St_Right;
      } else {
        v_6 = v_4;
        v_5 = v_3;
      };
      v = (diR==3);
      if (v) {
        r_St_Down = true;
        s_St_Down = Remote_control__St_Up;
      } else {
        r_St_Down = v_6;
        s_St_Down = v_5;
      };
      s = s_St_Down;
      r = r_St_Down;
      break;
    default:
      break;
  };
  ck_1 = s;
  switch (ck_1) {
    case Remote_control__St_Idle:
      dir_St_Idle = 0;
      v_r_St_Idle = 0;
      v_l_St_Idle = 0;
      nr_St_Idle = false;
      ns_St_Idle = Remote_control__St_Idle;
      _out->v_l = v_l_St_Idle;
      _out->v_r = v_r_St_Idle;
      _out->dir = dir_St_Idle;
      ns = ns_St_Idle;
      nr = nr_St_Idle;
      break;
    case Remote_control__St_Up:
      dir_St_Up = 0;
      v_r_St_Up = 30;
      v_l_St_Up = 30;
      nr_St_Up = false;
      ns_St_Up = Remote_control__St_Up;
      _out->v_l = v_l_St_Up;
      _out->v_r = v_r_St_Up;
      _out->dir = dir_St_Up;
      ns = ns_St_Up;
      nr = nr_St_Up;
      break;
    case Remote_control__St_Right:
      dir_St_Right = 2;
      v_r_St_Right = 30;
      v_l_St_Right = 30;
      nr_St_Right = false;
      ns_St_Right = Remote_control__St_Right;
      _out->v_l = v_l_St_Right;
      _out->v_r = v_r_St_Right;
      _out->dir = dir_St_Right;
      ns = ns_St_Right;
      nr = nr_St_Right;
      break;
    case Remote_control__St_Left:
      dir_St_Left = 1;
      v_r_St_Left = 30;
      v_l_St_Left = 30;
      nr_St_Left = false;
      ns_St_Left = Remote_control__St_Left;
      _out->v_l = v_l_St_Left;
      _out->v_r = v_r_St_Left;
      _out->dir = dir_St_Left;
      ns = ns_St_Left;
      nr = nr_St_Left;
      break;
    case Remote_control__St_Down:
      dir_St_Down = 3;
      v_r_St_Down = 30;
      v_l_St_Down = 30;
      nr_St_Down = false;
      ns_St_Down = Remote_control__St_Down;
      _out->v_l = v_l_St_Down;
      _out->v_r = v_r_St_Down;
      _out->dir = dir_St_Down;
      ns = ns_St_Down;
      nr = nr_St_Down;
      break;
    default:
      break;
  };
  self->pnr = nr;
  self->ck = ns;;
}

void Remote_control__main_reset(Remote_control__main_mem* self) {
  Remote_control__manual_control_reset(&self->manual_control);
  self->pnr = false;
  self->ck = Remote_control__St_1_Run;
}

void Remote_control__main_step(int diR, Remote_control__main_out* _out,
                               Remote_control__main_mem* self) {
  Remote_control__manual_control_out Remote_control__manual_control_out_st;
  
  int v;
  int v_38;
  int r_St_1_Stopped;
  Remote_control__st_1 s_St_1_Stopped;
  int r_St_1_Run;
  Remote_control__st_1 s_St_1_Run;
  int r_1;
  int nr_St_1_Stopped;
  Remote_control__st_1 ns_St_1_Stopped;
  int dir_St_1_Stopped;
  int v_r_St_1_Stopped;
  int v_l_St_1_Stopped;
  int nr_St_1_Run;
  Remote_control__st_1 ns_St_1_Run;
  int dir_St_1_Run;
  int v_r_St_1_Run;
  int v_l_St_1_Run;
  Remote_control__st_1 ck_2;
  Remote_control__st_1 s;
  Remote_control__st_1 ns;
  int r;
  int nr;
  switch (self->ck) {
    case Remote_control__St_1_Run:
      v_38 = (diR==5);
      if (v_38) {
        r_St_1_Run = true;
        s_St_1_Run = Remote_control__St_1_Stopped;
      } else {
        r_St_1_Run = self->pnr;
        s_St_1_Run = Remote_control__St_1_Run;
      };
      s = s_St_1_Run;
      r = r_St_1_Run;
      break;
    case Remote_control__St_1_Stopped:
      v = (diR==5);
      if (v) {
        r_St_1_Stopped = true;
        s_St_1_Stopped = Remote_control__St_1_Run;
      } else {
        r_St_1_Stopped = self->pnr;
        s_St_1_Stopped = Remote_control__St_1_Stopped;
      };
      s = s_St_1_Stopped;
      r = r_St_1_Stopped;
      break;
    default:
      break;
  };
  ck_2 = s;
  switch (ck_2) {
    case Remote_control__St_1_Run:
      nr_St_1_Run = false;
      ns_St_1_Run = Remote_control__St_1_Run;
      r_1 = r;
      if (r_1) {
        Remote_control__manual_control_reset(&self->manual_control);
      };
      Remote_control__manual_control_step(diR,
                                          &Remote_control__manual_control_out_st,
                                          &self->manual_control);
      v_l_St_1_Run = Remote_control__manual_control_out_st.v_l;
      v_r_St_1_Run = Remote_control__manual_control_out_st.v_r;
      dir_St_1_Run = Remote_control__manual_control_out_st.dir;
      _out->v_l = v_l_St_1_Run;
      _out->v_r = v_r_St_1_Run;
      _out->dir = dir_St_1_Run;
      ns = ns_St_1_Run;
      nr = nr_St_1_Run;
      break;
    case Remote_control__St_1_Stopped:
      dir_St_1_Stopped = 0;
      v_r_St_1_Stopped = 0;
      v_l_St_1_Stopped = 0;
      nr_St_1_Stopped = false;
      ns_St_1_Stopped = Remote_control__St_1_Stopped;
      _out->v_l = v_l_St_1_Stopped;
      _out->v_r = v_r_St_1_Stopped;
      _out->dir = dir_St_1_Stopped;
      ns = ns_St_1_Stopped;
      nr = nr_St_1_Stopped;
      break;
    default:
      break;
  };
  self->pnr = nr;
  self->ck = ns;;
}

