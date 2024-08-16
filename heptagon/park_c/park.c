/* --- Generated the 11/4/2024 at 19:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts park.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "park.h"

void Park__calculatePID_reset(Park__calculatePID_mem* self) {
  self->v_3 = true;
  self->v = true;
}

void Park__calculatePID_step(float error, Park__calculatePID_out* _out,
                             Park__calculatePID_mem* self) {
  
  float v_9;
  float v_8;
  float v_7;
  float v_6;
  float v_5;
  float v_2;
  float p;
  float i;
  float d;
  if (self->v_3) {
    v_5 = 0.000000;
  } else {
    v_5 = self->v_4;
  };
  d = (error-v_5);
  v_9 = (Park__kd*d);
  v_2 = (self->v_1+error);
  if (self->v) {
    i = 0.000000;
  } else {
    i = v_2;
  };
  v_7 = (Park__ki*i);
  p = error;
  v_6 = (Park__kp*p);
  v_8 = (v_6+v_7);
  _out->pidValue = (v_8+v_9);
  self->v_4 = error;
  self->v_3 = false;
  self->v_1 = i;
  self->v = false;;
}

void Park__calculateError_step(float sen[5], Park__calculateError_out* _out) {
  
  float v_20;
  float v_19;
  float v_18;
  float v_17;
  float v_16;
  float v_15;
  float v_14;
  float v_13;
  float v_12;
  float v_11;
  float v_10;
  float v;
  float left_weighted_sum;
  float right_weighted_sum;
  v_19 = 0.350000;
  v_18 = sen[4];
  v_20 = (v_18*v_19);
  v_16 = 0.405000;
  v_15 = sen[3];
  v_17 = (v_15*v_16);
  right_weighted_sum = (v_17+v_20);
  v_13 = 0.280000;
  v_12 = sen[1];
  v = sen[0];
  v_14 = (v_12*v_13);
  v_10 = 0.350000;
  v_11 = (v*v_10);
  left_weighted_sum = (v_11+v_14);
  _out->error = (left_weighted_sum-right_weighted_sum);;
}

void Park__parking_reset(Park__parking_mem* self) {
  self->v_31 = true;
  self->v_21 = true;
  self->pnr = false;
  self->ck = Park__St_Turn;
}

void Park__parking_step(int beacon, int diR, Park__parking_out* _out,
                        Park__parking_mem* self) {
  
  int v_29;
  int v_27;
  int v_25;
  int v_24;
  int v_22;
  int v;
  int v_39;
  int v_37;
  int v_35;
  int v_34;
  int v_32;
  int v_30;
  int nr_St_Stationary;
  Park__st ns_St_Stationary;
  int timer_St_Stationary;
  int dir_St_Stationary;
  int v_r_St_Stationary;
  int v_l_St_Stationary;
  int nr_St_Forward;
  Park__st ns_St_Forward;
  int timer_St_Forward;
  int dir_St_Forward;
  int v_r_St_Forward;
  int v_l_St_Forward;
  int nr_St_Turn;
  Park__st ns_St_Turn;
  int timer_St_Turn;
  int dir_St_Turn;
  int v_r_St_Turn;
  int v_l_St_Turn;
  Park__st ns;
  int r;
  int nr;
  int timer;
  r = self->pnr;
  switch (self->ck) {
    case Park__St_Turn:
      dir_St_Turn = diR;
      v_r_St_Turn = 30;
      v_l_St_Turn = 30;
      v_37 = (self->v_36-1);
      v_34 = (self->v_33>0);
      v_35 = (v_34&&beacon);
      if (v_35) {
        v_39 = v_37;
      } else {
        v_39 = self->v_38;
      };
      if (self->v_31) {
        v_32 = true;
      } else {
        v_32 = r;
      };
      if (v_32) {
        timer_St_Turn = 2;
      } else {
        timer_St_Turn = v_39;
      };
      _out->v_l = v_l_St_Turn;
      _out->v_r = v_r_St_Turn;
      _out->dir = dir_St_Turn;
      timer = timer_St_Turn;
      v_30 = (timer<=0);
      if (v_30) {
        nr_St_Turn = true;
        ns_St_Turn = Park__St_Forward;
      } else {
        nr_St_Turn = false;
        ns_St_Turn = Park__St_Turn;
      };
      ns = ns_St_Turn;
      nr = nr_St_Turn;
      self->v_38 = timer;
      self->v_36 = timer;
      self->v_33 = timer;
      self->v_31 = false;
      break;
    case Park__St_Forward:
      dir_St_Forward = 0;
      v_r_St_Forward = 38;
      v_l_St_Forward = 38;
      v_27 = (self->v_26-1);
      v_24 = (self->v_23>0);
      v_25 = (v_24&&beacon);
      if (v_25) {
        v_29 = v_27;
      } else {
        v_29 = self->v_28;
      };
      if (self->v_21) {
        v_22 = true;
      } else {
        v_22 = r;
      };
      if (v_22) {
        timer_St_Forward = 3;
      } else {
        timer_St_Forward = v_29;
      };
      _out->v_l = v_l_St_Forward;
      _out->v_r = v_r_St_Forward;
      _out->dir = dir_St_Forward;
      timer = timer_St_Forward;
      v = (timer<=0);
      if (v) {
        nr_St_Forward = true;
        ns_St_Forward = Park__St_Stationary;
      } else {
        nr_St_Forward = false;
        ns_St_Forward = Park__St_Forward;
      };
      ns = ns_St_Forward;
      nr = nr_St_Forward;
      self->v_28 = timer;
      self->v_26 = timer;
      self->v_23 = timer;
      self->v_21 = false;
      break;
    case Park__St_Stationary:
      dir_St_Stationary = 0;
      v_r_St_Stationary = 0;
      v_l_St_Stationary = 0;
      timer_St_Stationary = 0;
      nr_St_Stationary = false;
      ns_St_Stationary = Park__St_Stationary;
      _out->v_l = v_l_St_Stationary;
      _out->v_r = v_r_St_Stationary;
      _out->dir = dir_St_Stationary;
      timer = timer_St_Stationary;
      ns = ns_St_Stationary;
      nr = nr_St_Stationary;
      break;
    default:
      break;
  };
  self->pnr = nr;
  self->ck = ns;;
}

void Park__calculateMotor3_reset(Park__calculateMotor3_mem* self) {
  Park__parking_reset(&self->parking_1);
  Park__parking_reset(&self->parking);
  self->pnr = false;
  self->ck = Park__St_1_Turn;
  self->v_52 = true;
}

void Park__calculateMotor3_step(int irSen1, int irSen2, int irSen3,
                                int irSen4, float pidValue, int beacon,
                                Park__calculateMotor3_out* _out,
                                Park__calculateMotor3_mem* self) {
  Mc_ext__int_of_float_out Mc_ext__int_of_float_out_st;
  Park__parking_out Park__parking_out_st;
  
  int v_46;
  Park__st_1 v_45;
  int v_44;
  int v_43;
  int v_42;
  int v_41;
  int v_40;
  int v;
  int r_St_1_Parking2;
  Park__st_1 s_St_1_Parking2;
  int r_St_1_Parking1;
  Park__st_1 s_St_1_Parking1;
  int r_St_1_Forward;
  Park__st_1 s_St_1_Forward;
  int r_St_1_Turn;
  Park__st_1 s_St_1_Turn;
  int r_1;
  int r_2;
  int v_50;
  float v_49;
  int v_48;
  float v_47;
  int v_64;
  float v_63;
  int v_62;
  float v_61;
  int v_60;
  int v_58;
  int v_56;
  int v_55;
  int v_53;
  int v_51;
  int nr_St_1_Parking2;
  Park__st_1 ns_St_1_Parking2;
  int timer_St_1_Parking2;
  int diR_St_1_Parking2;
  int vr_St_1_Parking2;
  int vl_St_1_Parking2;
  int nr_St_1_Parking1;
  Park__st_1 ns_St_1_Parking1;
  int timer_St_1_Parking1;
  int diR_St_1_Parking1;
  int vr_St_1_Parking1;
  int vl_St_1_Parking1;
  int nr_St_1_Forward;
  Park__st_1 ns_St_1_Forward;
  int timer_St_1_Forward;
  int diR_St_1_Forward;
  int vr_St_1_Forward;
  int vl_St_1_Forward;
  int nr_St_1_Turn;
  Park__st_1 ns_St_1_Turn;
  int timer_St_1_Turn;
  int diR_St_1_Turn;
  int vr_St_1_Turn;
  int vl_St_1_Turn;
  Park__st_1 ck_1;
  Park__st_1 s;
  Park__st_1 ns;
  int r;
  int nr;
  int vl;
  int vr;
  int diR;
  int timer;
  switch (self->ck) {
    case Park__St_1_Turn:
      r_St_1_Turn = self->pnr;
      s_St_1_Turn = Park__St_1_Turn;
      s = s_St_1_Turn;
      r = r_St_1_Turn;
      break;
    case Park__St_1_Forward:
      v_43 = (irSen2==1);
      v_42 = (irSen1==1);
      v_44 = (v_42&&v_43);
      if (v_44) {
        v_46 = true;
        v_45 = Park__St_1_Parking2;
      } else {
        v_46 = self->pnr;
        v_45 = Park__St_1_Forward;
      };
      v_40 = (irSen4==1);
      v = (irSen3==1);
      v_41 = (v&&v_40);
      if (v_41) {
        r_St_1_Forward = true;
        s_St_1_Forward = Park__St_1_Parking1;
      } else {
        r_St_1_Forward = v_46;
        s_St_1_Forward = v_45;
      };
      s = s_St_1_Forward;
      r = r_St_1_Forward;
      break;
    case Park__St_1_Parking1:
      r_St_1_Parking1 = self->pnr;
      s_St_1_Parking1 = Park__St_1_Parking1;
      s = s_St_1_Parking1;
      r = r_St_1_Parking1;
      break;
    case Park__St_1_Parking2:
      r_St_1_Parking2 = self->pnr;
      s_St_1_Parking2 = Park__St_1_Parking2;
      s = s_St_1_Parking2;
      r = r_St_1_Parking2;
      break;
    default:
      break;
  };
  ck_1 = s;
  switch (ck_1) {
    case Park__St_1_Turn:
      diR_St_1_Turn = self->diR_3;
      v_63 = (0.500000*pidValue);
      Mc_ext__int_of_float_step(v_63, &Mc_ext__int_of_float_out_st);
      v_64 = Mc_ext__int_of_float_out_st.o;
      vr_St_1_Turn = (30-v_64);
      v_61 = (0.500000*pidValue);
      Mc_ext__int_of_float_step(v_61, &Mc_ext__int_of_float_out_st);
      v_62 = Mc_ext__int_of_float_out_st.o;
      vl_St_1_Turn = (30+v_62);
      v_58 = (self->v_57-1);
      v_55 = (self->v_54>0);
      v_56 = (v_55&&beacon);
      if (v_56) {
        v_60 = v_58;
      } else {
        v_60 = self->v_59;
      };
      if (self->v_52) {
        v_53 = true;
      } else {
        v_53 = r;
      };
      if (v_53) {
        timer_St_1_Turn = 4;
      } else {
        timer_St_1_Turn = v_60;
      };
      vl = vl_St_1_Turn;
      vr = vr_St_1_Turn;
      diR = diR_St_1_Turn;
      timer = timer_St_1_Turn;
      v_51 = (timer<=0);
      if (v_51) {
        nr_St_1_Turn = true;
        ns_St_1_Turn = Park__St_1_Forward;
      } else {
        nr_St_1_Turn = false;
        ns_St_1_Turn = Park__St_1_Turn;
      };
      ns = ns_St_1_Turn;
      nr = nr_St_1_Turn;
      break;
    case Park__St_1_Forward:
      timer_St_1_Forward = 0;
      diR_St_1_Forward = 0;
      v_49 = (0.500000*pidValue);
      Mc_ext__int_of_float_step(v_49, &Mc_ext__int_of_float_out_st);
      v_50 = Mc_ext__int_of_float_out_st.o;
      vr_St_1_Forward = (30-v_50);
      v_47 = (0.500000*pidValue);
      Mc_ext__int_of_float_step(v_47, &Mc_ext__int_of_float_out_st);
      v_48 = Mc_ext__int_of_float_out_st.o;
      vl_St_1_Forward = (30+v_48);
      nr_St_1_Forward = false;
      ns_St_1_Forward = Park__St_1_Forward;
      vl = vl_St_1_Forward;
      vr = vr_St_1_Forward;
      diR = diR_St_1_Forward;
      timer = timer_St_1_Forward;
      ns = ns_St_1_Forward;
      nr = nr_St_1_Forward;
      break;
    case Park__St_1_Parking1:
      timer_St_1_Parking1 = 0;
      nr_St_1_Parking1 = false;
      ns_St_1_Parking1 = Park__St_1_Parking1;
      r_2 = r;
      if (r_2) {
        Park__parking_reset(&self->parking_1);
      };
      Park__parking_step(beacon, 2, &Park__parking_out_st, &self->parking_1);
      vl_St_1_Parking1 = Park__parking_out_st.v_l;
      vr_St_1_Parking1 = Park__parking_out_st.v_r;
      diR_St_1_Parking1 = Park__parking_out_st.dir;
      vl = vl_St_1_Parking1;
      vr = vr_St_1_Parking1;
      diR = diR_St_1_Parking1;
      timer = timer_St_1_Parking1;
      ns = ns_St_1_Parking1;
      nr = nr_St_1_Parking1;
      break;
    case Park__St_1_Parking2:
      timer_St_1_Parking2 = 0;
      nr_St_1_Parking2 = false;
      ns_St_1_Parking2 = Park__St_1_Parking2;
      r_1 = r;
      if (r_1) {
        Park__parking_reset(&self->parking);
      };
      Park__parking_step(beacon, 1, &Park__parking_out_st, &self->parking);
      vl_St_1_Parking2 = Park__parking_out_st.v_l;
      vr_St_1_Parking2 = Park__parking_out_st.v_r;
      diR_St_1_Parking2 = Park__parking_out_st.dir;
      vl = vl_St_1_Parking2;
      vr = vr_St_1_Parking2;
      diR = diR_St_1_Parking2;
      timer = timer_St_1_Parking2;
      ns = ns_St_1_Parking2;
      nr = nr_St_1_Parking2;
      break;
    default:
      break;
  };
  _out->dir = diR;
  _out->v_r = vr;
  _out->v_l = vl;
  self->diR_3 = diR;
  self->vr_1 = vr;
  self->vl_1 = vl;
  self->pnr = nr;
  self->ck = ns;
  switch (ck_1) {
    case Park__St_1_Turn:
      self->v_59 = timer;
      self->v_57 = timer;
      self->v_54 = timer;
      self->v_52 = false;
      break;
    default:
      break;
  };;
}

void Park__main_reset(Park__main_mem* self) {
  Park__calculatePID_reset(&self->calculatePID);
  Park__calculateMotor3_reset(&self->calculateMotor3);
}

void Park__main_step(int sen0, int sen1, int sen2, int sen3, int sen4,
                     int irSen1, int irSen2, int irSen3, int irSen4,
                     int beacon, Park__main_out* _out, Park__main_mem* self) {
  Park__calculateMotor3_out Park__calculateMotor3_out_st;
  Mc_ext__float_of_int_out Mc_ext__float_of_int_out_st;
  Park__calculatePID_out Park__calculatePID_out_st;
  Park__calculateError_out Park__calculateError_out_st;
  
  float v_68;
  float v_67;
  float v_66;
  float v_65;
  float v;
  float sen[5];
  float error;
  float pidValue;
  Mc_ext__float_of_int_step(sen4, &Mc_ext__float_of_int_out_st);
  v_68 = Mc_ext__float_of_int_out_st.o;
  Mc_ext__float_of_int_step(sen3, &Mc_ext__float_of_int_out_st);
  v_67 = Mc_ext__float_of_int_out_st.o;
  Mc_ext__float_of_int_step(sen2, &Mc_ext__float_of_int_out_st);
  v_66 = Mc_ext__float_of_int_out_st.o;
  Mc_ext__float_of_int_step(sen1, &Mc_ext__float_of_int_out_st);
  v_65 = Mc_ext__float_of_int_out_st.o;
  Mc_ext__float_of_int_step(sen0, &Mc_ext__float_of_int_out_st);
  v = Mc_ext__float_of_int_out_st.o;
  sen[0] = v;
  sen[1] = v_65;
  sen[2] = v_66;
  sen[3] = v_67;
  sen[4] = v_68;
  Park__calculateError_step(sen, &Park__calculateError_out_st);
  error = Park__calculateError_out_st.error;
  Park__calculatePID_step(error, &Park__calculatePID_out_st,
                          &self->calculatePID);
  pidValue = Park__calculatePID_out_st.pidValue;
  Park__calculateMotor3_step(irSen1, irSen2, irSen3, irSen4, pidValue,
                             beacon, &Park__calculateMotor3_out_st,
                             &self->calculateMotor3);
  _out->v_l = Park__calculateMotor3_out_st.v_l;
  _out->v_r = Park__calculateMotor3_out_st.v_r;
  _out->dir = Park__calculateMotor3_out_st.dir;;
}

