/* --- Generated the 11/4/2024 at 19:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower.h"

void Line_follower__calculatePID_reset(Line_follower__calculatePID_mem* self) {
  self->v_3 = true;
  self->v = true;
}

void Line_follower__calculatePID_step(float error,
                                      Line_follower__calculatePID_out* _out,
                                      Line_follower__calculatePID_mem* self) {
  
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
  v_9 = (Line_follower__kd*d);
  v_2 = (self->v_1+error);
  if (self->v) {
    i = 0.000000;
  } else {
    i = v_2;
  };
  v_7 = (Line_follower__ki*i);
  p = error;
  v_6 = (Line_follower__kp*p);
  v_8 = (v_6+v_7);
  _out->pidValue = (v_8+v_9);
  self->v_4 = error;
  self->v_3 = false;
  self->v_1 = i;
  self->v = false;;
}

void Line_follower__calculateError_step(float sen[5], float weights[4],
                                        Line_follower__calculateError_out* _out) {
  
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
  v_19 = weights[3];
  v_18 = sen[4];
  v_20 = (v_18*v_19);
  v_16 = weights[2];
  v_15 = sen[3];
  v_17 = (v_15*v_16);
  right_weighted_sum = (v_17+v_20);
  v_13 = weights[1];
  v_10 = weights[0];
  v_12 = sen[1];
  v = sen[0];
  v_14 = (v_12*v_13);
  v_11 = (v*v_10);
  left_weighted_sum = (v_11+v_14);
  _out->error = (left_weighted_sum-right_weighted_sum);;
}

void Line_follower__calculateMotor1_reset(Line_follower__calculateMotor1_mem* self) {
  self->pnr = false;
  self->ck = Line_follower__St_Forward;
}

void Line_follower__calculateMotor1_step(float pidValue,
                                         Line_follower__calculateMotor1_out* _out,
                                         Line_follower__calculateMotor1_mem* self) {
  Mc_ext__int_of_float_out Mc_ext__int_of_float_out_st;
  
  int v_25;
  Line_follower__st v_24;
  int v_23;
  int v_22;
  int v_21;
  int v;
  int v_31;
  Line_follower__st v_30;
  int v_29;
  int v_28;
  int v_27;
  int v_26;
  int v_35;
  Line_follower__st v_34;
  int v_33;
  int v_32;
  int r_St_Hardright;
  Line_follower__st s_St_Hardright;
  int r_St_Hardleft;
  Line_follower__st s_St_Hardleft;
  int r_St_Forward;
  Line_follower__st s_St_Forward;
  int v_39;
  float v_38;
  int v_37;
  float v_36;
  int nr_St_Hardright;
  Line_follower__st ns_St_Hardright;
  int diR_St_Hardright;
  int vr_St_Hardright;
  int vl_St_Hardright;
  int nr_St_Hardleft;
  Line_follower__st ns_St_Hardleft;
  int diR_St_Hardleft;
  int vr_St_Hardleft;
  int vl_St_Hardleft;
  int nr_St_Forward;
  Line_follower__st ns_St_Forward;
  int diR_St_Forward;
  int vr_St_Forward;
  int vl_St_Forward;
  Line_follower__st ck_1;
  Line_follower__st s;
  Line_follower__st ns;
  int r;
  int nr;
  int vl;
  int vr;
  int diR;
  switch (self->ck) {
    case Line_follower__St_Forward:
      v_33 = (pidValue<Line_follower__t_large_neg);
      if (v_33) {
        v_35 = true;
        v_34 = Line_follower__St_Hardright;
      } else {
        v_35 = self->pnr;
        v_34 = Line_follower__St_Forward;
      };
      v_32 = (pidValue>Line_follower__t_large_pos);
      if (v_32) {
        r_St_Forward = true;
        s_St_Forward = Line_follower__St_Hardleft;
      } else {
        r_St_Forward = v_35;
        s_St_Forward = v_34;
      };
      s = s_St_Forward;
      r = r_St_Forward;
      break;
    case Line_follower__St_Hardleft:
      v_29 = (pidValue<Line_follower__t_large_neg);
      if (v_29) {
        v_31 = true;
        v_30 = Line_follower__St_Hardright;
      } else {
        v_31 = self->pnr;
        v_30 = Line_follower__St_Hardleft;
      };
      v_27 = (pidValue<Line_follower__t_small_pos);
      v_26 = (pidValue>Line_follower__t_small_neg);
      v_28 = (v_26&&v_27);
      if (v_28) {
        r_St_Hardleft = true;
        s_St_Hardleft = Line_follower__St_Forward;
      } else {
        r_St_Hardleft = v_31;
        s_St_Hardleft = v_30;
      };
      s = s_St_Hardleft;
      r = r_St_Hardleft;
      break;
    case Line_follower__St_Hardright:
      v_23 = (pidValue>Line_follower__t_large_pos);
      if (v_23) {
        v_25 = true;
        v_24 = Line_follower__St_Hardleft;
      } else {
        v_25 = self->pnr;
        v_24 = Line_follower__St_Hardright;
      };
      v_21 = (pidValue<Line_follower__t_small_pos);
      v = (pidValue>Line_follower__t_small_neg);
      v_22 = (v&&v_21);
      if (v_22) {
        r_St_Hardright = true;
        s_St_Hardright = Line_follower__St_Forward;
      } else {
        r_St_Hardright = v_25;
        s_St_Hardright = v_24;
      };
      s = s_St_Hardright;
      r = r_St_Hardright;
      break;
    default:
      break;
  };
  ck_1 = s;
  switch (ck_1) {
    case Line_follower__St_Forward:
      diR_St_Forward = 0;
      v_38 = (0.500000*pidValue);
      Mc_ext__int_of_float_step(v_38, &Mc_ext__int_of_float_out_st);
      v_39 = Mc_ext__int_of_float_out_st.o;
      vr_St_Forward = (30+v_39);
      v_36 = (0.500000*pidValue);
      Mc_ext__int_of_float_step(v_36, &Mc_ext__int_of_float_out_st);
      v_37 = Mc_ext__int_of_float_out_st.o;
      vl_St_Forward = (30-v_37);
      nr_St_Forward = false;
      ns_St_Forward = Line_follower__St_Forward;
      vl = vl_St_Forward;
      vr = vr_St_Forward;
      diR = diR_St_Forward;
      ns = ns_St_Forward;
      nr = nr_St_Forward;
      break;
    case Line_follower__St_Hardleft:
      diR_St_Hardleft = 1;
      vr_St_Hardleft = 150;
      vl_St_Hardleft = 130;
      nr_St_Hardleft = false;
      ns_St_Hardleft = Line_follower__St_Hardleft;
      vl = vl_St_Hardleft;
      vr = vr_St_Hardleft;
      diR = diR_St_Hardleft;
      ns = ns_St_Hardleft;
      nr = nr_St_Hardleft;
      break;
    case Line_follower__St_Hardright:
      diR_St_Hardright = 2;
      vr_St_Hardright = 130;
      vl_St_Hardright = 150;
      nr_St_Hardright = false;
      ns_St_Hardright = Line_follower__St_Hardright;
      vl = vl_St_Hardright;
      vr = vr_St_Hardright;
      diR = diR_St_Hardright;
      ns = ns_St_Hardright;
      nr = nr_St_Hardright;
      break;
    default:
      break;
  };
  _out->dir = diR;
  _out->v_r = vr;
  _out->v_l = vl;
  self->diR_2 = diR;
  self->vr_2 = vr;
  self->vl_2 = vl;
  self->pnr = nr;
  self->ck = ns;;
}

void Line_follower__calculateMotor2_reset(Line_follower__calculateMotor2_mem* self) {
  self->pnr = false;
  self->ck = Line_follower__St_1_Forward;
}

void Line_follower__calculateMotor2_step(float sen[5], float pidValue,
                                         int count, int flag,
                                         Line_follower__calculateMotor2_out* _out,
                                         Line_follower__calculateMotor2_mem* self) {
  Mc_ext__int_of_float_out Mc_ext__int_of_float_out_st;
  
  int v_93;
  Line_follower__st_1 v_92;
  int v_91;
  int v_90;
  int v_89;
  float v_88;
  int v_87;
  int v_86;
  float v_85;
  int v_84;
  float v_83;
  int v_82;
  int v_81;
  int v_80;
  float v_79;
  int v_78;
  int v_77;
  float v_76;
  int v_75;
  float v_74;
  int v_73;
  int v_72;
  float v_71;
  int v_70;
  int v_69;
  float v_68;
  int v_67;
  float v_66;
  int v_65;
  int v_64;
  int v_63;
  int v_62;
  float v_61;
  int v_60;
  int v_59;
  float v_58;
  int v_57;
  float v_56;
  int v_55;
  int v_54;
  int v_53;
  float v_52;
  int v_51;
  int v_50;
  float v_49;
  int v_48;
  float v_47;
  int v_46;
  int v_45;
  float v_44;
  int v_43;
  int v_42;
  float v_41;
  int v_40;
  float v;
  int v_148;
  Line_follower__st_1 v_147;
  int v_146;
  int v_145;
  int v_144;
  float v_143;
  int v_142;
  int v_141;
  float v_140;
  int v_139;
  float v_138;
  int v_137;
  int v_136;
  int v_135;
  float v_134;
  int v_133;
  int v_132;
  float v_131;
  int v_130;
  float v_129;
  int v_128;
  int v_127;
  float v_126;
  int v_125;
  int v_124;
  float v_123;
  int v_122;
  float v_121;
  int v_120;
  int v_119;
  int v_118;
  int v_117;
  float v_116;
  int v_115;
  int v_114;
  float v_113;
  int v_112;
  float v_111;
  int v_110;
  int v_109;
  int v_108;
  float v_107;
  int v_106;
  int v_105;
  float v_104;
  int v_103;
  float v_102;
  int v_101;
  int v_100;
  float v_99;
  int v_98;
  int v_97;
  float v_96;
  int v_95;
  float v_94;
  int v_203;
  Line_follower__st_1 v_202;
  int v_201;
  int v_200;
  int v_199;
  float v_198;
  int v_197;
  int v_196;
  float v_195;
  int v_194;
  float v_193;
  int v_192;
  int v_191;
  int v_190;
  float v_189;
  int v_188;
  int v_187;
  float v_186;
  int v_185;
  float v_184;
  int v_183;
  int v_182;
  float v_181;
  int v_180;
  int v_179;
  float v_178;
  int v_177;
  float v_176;
  int v_175;
  int v_174;
  int v_173;
  int v_172;
  float v_171;
  int v_170;
  int v_169;
  float v_168;
  int v_167;
  float v_166;
  int v_165;
  int v_164;
  int v_163;
  float v_162;
  int v_161;
  int v_160;
  float v_159;
  int v_158;
  float v_157;
  int v_156;
  int v_155;
  float v_154;
  int v_153;
  int v_152;
  float v_151;
  int v_150;
  float v_149;
  int v_215;
  Line_follower__st_1 v_214;
  int v_213;
  Line_follower__st_1 v_212;
  int v_211;
  int v_210;
  int v_209;
  int v_208;
  int v_207;
  int v_206;
  int v_205;
  int v_204;
  int r_St_1_Noderight;
  Line_follower__st_1 s_St_1_Noderight;
  int r_St_1_Nodeleft;
  Line_follower__st_1 s_St_1_Nodeleft;
  int r_St_1_Nodeone;
  Line_follower__st_1 s_St_1_Nodeone;
  int r_St_1_Forward;
  Line_follower__st_1 s_St_1_Forward;
  int v_219;
  float v_218;
  int v_217;
  float v_216;
  int nr_St_1_Noderight;
  Line_follower__st_1 ns_St_1_Noderight;
  int diR_St_1_Noderight;
  int vr_St_1_Noderight;
  int vl_St_1_Noderight;
  int nr_St_1_Nodeleft;
  Line_follower__st_1 ns_St_1_Nodeleft;
  int diR_St_1_Nodeleft;
  int vr_St_1_Nodeleft;
  int vl_St_1_Nodeleft;
  int nr_St_1_Nodeone;
  Line_follower__st_1 ns_St_1_Nodeone;
  int diR_St_1_Nodeone;
  int vr_St_1_Nodeone;
  int vl_St_1_Nodeone;
  int nr_St_1_Forward;
  Line_follower__st_1 ns_St_1_Forward;
  int diR_St_1_Forward;
  int vr_St_1_Forward;
  int vl_St_1_Forward;
  Line_follower__st_1 ck_2;
  Line_follower__st_1 s;
  Line_follower__st_1 ns;
  int r;
  int nr;
  int vl;
  int vr;
  int diR;
  switch (self->ck) {
    case Line_follower__St_1_Forward:
      v_209 = (count==4);
      v_208 = (count==3);
      v_210 = (v_208||v_209);
      v_211 = (flag&&v_210);
      if (v_211) {
        v_213 = true;
        v_212 = Line_follower__St_1_Nodeleft;
      } else {
        v_213 = self->pnr;
        v_212 = Line_follower__St_1_Forward;
      };
      v_206 = (count==2);
      v_207 = (flag&&v_206);
      if (v_207) {
        v_215 = true;
        v_214 = Line_follower__St_1_Noderight;
      } else {
        v_215 = v_213;
        v_214 = v_212;
      };
      v_204 = (count==1);
      v_205 = (flag&&v_204);
      if (v_205) {
        r_St_1_Forward = true;
        s_St_1_Forward = Line_follower__St_1_Nodeone;
      } else {
        r_St_1_Forward = v_215;
        s_St_1_Forward = v_214;
      };
      s = s_St_1_Forward;
      r = r_St_1_Forward;
      break;
    case Line_follower__St_1_Nodeone:
      v_198 = sen[4];
      v_199 = (v_198>800.000000);
      v_195 = sen[3];
      v_196 = (v_195<500.000000);
      v_193 = sen[2];
      v_194 = (v_193>800.000000);
      v_197 = (v_194&&v_196);
      v_200 = (v_197&&v_199);
      v_189 = sen[2];
      v_190 = (v_189>800.000000);
      v_186 = sen[1];
      v_187 = (v_186<700.000000);
      v_184 = sen[0];
      v_185 = (v_184>800.000000);
      v_188 = (v_185&&v_187);
      v_191 = (v_188&&v_190);
      v_181 = sen[4];
      v_182 = (v_181>800.000000);
      v_178 = sen[2];
      v_179 = (v_178<700.000000);
      v_176 = sen[0];
      v_177 = (v_176>800.000000);
      v_180 = (v_177&&v_179);
      v_183 = (v_180&&v_182);
      v_192 = (v_183||v_191);
      v_201 = (v_192||v_200);
      if (v_201) {
        v_203 = true;
        v_202 = Line_follower__St_1_Forward;
      } else {
        v_203 = self->pnr;
        v_202 = Line_follower__St_1_Nodeone;
      };
      v_171 = sen[4];
      v_172 = (v_171>800.000000);
      v_168 = sen[3];
      v_169 = (v_168<500.000000);
      v_166 = sen[2];
      v_167 = (v_166>800.000000);
      v_170 = (v_167&&v_169);
      v_173 = (v_170&&v_172);
      v_162 = sen[2];
      v_163 = (v_162>800.000000);
      v_159 = sen[1];
      v_160 = (v_159<700.000000);
      v_157 = sen[0];
      v_158 = (v_157>800.000000);
      v_161 = (v_158&&v_160);
      v_164 = (v_161&&v_163);
      v_154 = sen[4];
      v_155 = (v_154>800.000000);
      v_151 = sen[2];
      v_152 = (v_151<700.000000);
      v_149 = sen[0];
      v_150 = (v_149>800.000000);
      v_153 = (v_150&&v_152);
      v_156 = (v_153&&v_155);
      v_165 = (v_156||v_164);
      v_174 = (v_165||v_173);
      v_175 = !(v_174);
      if (v_175) {
        r_St_1_Nodeone = true;
        s_St_1_Nodeone = Line_follower__St_1_Nodeone;
      } else {
        r_St_1_Nodeone = v_203;
        s_St_1_Nodeone = v_202;
      };
      s = s_St_1_Nodeone;
      r = r_St_1_Nodeone;
      break;
    case Line_follower__St_1_Nodeleft:
      v_143 = sen[4];
      v_144 = (v_143>800.000000);
      v_140 = sen[3];
      v_141 = (v_140<500.000000);
      v_138 = sen[2];
      v_139 = (v_138>800.000000);
      v_142 = (v_139&&v_141);
      v_145 = (v_142&&v_144);
      v_134 = sen[2];
      v_135 = (v_134>800.000000);
      v_131 = sen[1];
      v_132 = (v_131<700.000000);
      v_129 = sen[0];
      v_130 = (v_129>800.000000);
      v_133 = (v_130&&v_132);
      v_136 = (v_133&&v_135);
      v_126 = sen[4];
      v_127 = (v_126>800.000000);
      v_123 = sen[2];
      v_124 = (v_123<700.000000);
      v_121 = sen[0];
      v_122 = (v_121>800.000000);
      v_125 = (v_122&&v_124);
      v_128 = (v_125&&v_127);
      v_137 = (v_128||v_136);
      v_146 = (v_137||v_145);
      if (v_146) {
        v_148 = true;
        v_147 = Line_follower__St_1_Forward;
      } else {
        v_148 = self->pnr;
        v_147 = Line_follower__St_1_Nodeleft;
      };
      v_116 = sen[4];
      v_117 = (v_116>800.000000);
      v_113 = sen[3];
      v_114 = (v_113<500.000000);
      v_111 = sen[2];
      v_112 = (v_111>800.000000);
      v_115 = (v_112&&v_114);
      v_118 = (v_115&&v_117);
      v_107 = sen[2];
      v_108 = (v_107>800.000000);
      v_104 = sen[1];
      v_105 = (v_104<700.000000);
      v_102 = sen[0];
      v_103 = (v_102>800.000000);
      v_106 = (v_103&&v_105);
      v_109 = (v_106&&v_108);
      v_99 = sen[4];
      v_100 = (v_99>800.000000);
      v_96 = sen[2];
      v_97 = (v_96<700.000000);
      v_94 = sen[0];
      v_95 = (v_94>800.000000);
      v_98 = (v_95&&v_97);
      v_101 = (v_98&&v_100);
      v_110 = (v_101||v_109);
      v_119 = (v_110||v_118);
      v_120 = !(v_119);
      if (v_120) {
        r_St_1_Nodeleft = true;
        s_St_1_Nodeleft = Line_follower__St_1_Nodeleft;
      } else {
        r_St_1_Nodeleft = v_148;
        s_St_1_Nodeleft = v_147;
      };
      s = s_St_1_Nodeleft;
      r = r_St_1_Nodeleft;
      break;
    case Line_follower__St_1_Noderight:
      v_88 = sen[4];
      v_89 = (v_88>800.000000);
      v_85 = sen[3];
      v_86 = (v_85<500.000000);
      v_83 = sen[2];
      v_84 = (v_83>800.000000);
      v_87 = (v_84&&v_86);
      v_90 = (v_87&&v_89);
      v_79 = sen[2];
      v_80 = (v_79>800.000000);
      v_76 = sen[1];
      v_77 = (v_76<700.000000);
      v_74 = sen[0];
      v_75 = (v_74>800.000000);
      v_78 = (v_75&&v_77);
      v_81 = (v_78&&v_80);
      v_71 = sen[4];
      v_72 = (v_71>800.000000);
      v_68 = sen[2];
      v_69 = (v_68<700.000000);
      v_66 = sen[0];
      v_67 = (v_66>800.000000);
      v_70 = (v_67&&v_69);
      v_73 = (v_70&&v_72);
      v_82 = (v_73||v_81);
      v_91 = (v_82||v_90);
      if (v_91) {
        v_93 = true;
        v_92 = Line_follower__St_1_Forward;
      } else {
        v_93 = self->pnr;
        v_92 = Line_follower__St_1_Noderight;
      };
      v_61 = sen[4];
      v_62 = (v_61>800.000000);
      v_58 = sen[3];
      v_59 = (v_58<500.000000);
      v_56 = sen[2];
      v_57 = (v_56>800.000000);
      v_60 = (v_57&&v_59);
      v_63 = (v_60&&v_62);
      v_52 = sen[2];
      v_53 = (v_52>800.000000);
      v_49 = sen[1];
      v_50 = (v_49<700.000000);
      v_47 = sen[0];
      v_48 = (v_47>800.000000);
      v_51 = (v_48&&v_50);
      v_54 = (v_51&&v_53);
      v_44 = sen[4];
      v_45 = (v_44>800.000000);
      v_41 = sen[2];
      v = sen[0];
      v_42 = (v_41<700.000000);
      v_40 = (v>800.000000);
      v_43 = (v_40&&v_42);
      v_46 = (v_43&&v_45);
      v_55 = (v_46||v_54);
      v_64 = (v_55||v_63);
      v_65 = !(v_64);
      if (v_65) {
        r_St_1_Noderight = true;
        s_St_1_Noderight = Line_follower__St_1_Noderight;
      } else {
        r_St_1_Noderight = v_93;
        s_St_1_Noderight = v_92;
      };
      s = s_St_1_Noderight;
      r = r_St_1_Noderight;
      break;
    default:
      break;
  };
  ck_2 = s;
  switch (ck_2) {
    case Line_follower__St_1_Forward:
      diR_St_1_Forward = 0;
      v_218 = (0.500000*pidValue);
      Mc_ext__int_of_float_step(v_218, &Mc_ext__int_of_float_out_st);
      v_219 = Mc_ext__int_of_float_out_st.o;
      vr_St_1_Forward = (30-v_219);
      v_216 = (0.500000*pidValue);
      Mc_ext__int_of_float_step(v_216, &Mc_ext__int_of_float_out_st);
      v_217 = Mc_ext__int_of_float_out_st.o;
      vl_St_1_Forward = (30+v_217);
      nr_St_1_Forward = false;
      ns_St_1_Forward = Line_follower__St_1_Forward;
      vl = vl_St_1_Forward;
      vr = vr_St_1_Forward;
      diR = diR_St_1_Forward;
      ns = ns_St_1_Forward;
      nr = nr_St_1_Forward;
      break;
    case Line_follower__St_1_Nodeone:
      diR_St_1_Nodeone = 0;
      vr_St_1_Nodeone = 10;
      vl_St_1_Nodeone = 30;
      nr_St_1_Nodeone = false;
      ns_St_1_Nodeone = Line_follower__St_1_Nodeone;
      vl = vl_St_1_Nodeone;
      vr = vr_St_1_Nodeone;
      diR = diR_St_1_Nodeone;
      ns = ns_St_1_Nodeone;
      nr = nr_St_1_Nodeone;
      break;
    case Line_follower__St_1_Nodeleft:
      diR_St_1_Nodeleft = 0;
      vr_St_1_Nodeleft = 40;
      vl_St_1_Nodeleft = 10;
      nr_St_1_Nodeleft = false;
      ns_St_1_Nodeleft = Line_follower__St_1_Nodeleft;
      vl = vl_St_1_Nodeleft;
      vr = vr_St_1_Nodeleft;
      diR = diR_St_1_Nodeleft;
      ns = ns_St_1_Nodeleft;
      nr = nr_St_1_Nodeleft;
      break;
    case Line_follower__St_1_Noderight:
      diR_St_1_Noderight = 0;
      vr_St_1_Noderight = 10;
      vl_St_1_Noderight = 30;
      nr_St_1_Noderight = false;
      ns_St_1_Noderight = Line_follower__St_1_Noderight;
      vl = vl_St_1_Noderight;
      vr = vr_St_1_Noderight;
      diR = diR_St_1_Noderight;
      ns = ns_St_1_Noderight;
      nr = nr_St_1_Noderight;
      break;
    default:
      break;
  };
  _out->dir = diR;
  _out->v_r = vr;
  _out->v_l = vl;
  self->diR_3 = diR;
  self->vr_3 = vr;
  self->vl_3 = vl;
  self->pnr = nr;
  self->ck = ns;;
}

void Line_follower__counter_reset(Line_follower__counter_mem* self) {
  self->beaconcount_1 = 0;
  self->flg_1 = false;
  self->cnt_2 = 0;
  self->pnr = false;
  self->ck = Line_follower__St_2_Ready;
}

void Line_follower__counter_step(float sen[5], int beacon, int second,
                                 Line_follower__counter_out* _out,
                                 Line_follower__counter_mem* self) {
  
  int v;
  int v_229;
  int v_228;
  float v_227;
  int v_226;
  int v_225;
  float v_224;
  int v_223;
  int v_222;
  float v_221;
  int v_220;
  int r_St_2_Wait;
  Line_follower__st_2 s_St_2_Wait;
  int r_St_2_Increment;
  Line_follower__st_2 s_St_2_Increment;
  int r_St_2_Ready;
  Line_follower__st_2 s_St_2_Ready;
  int nr_St_2_Wait;
  Line_follower__st_2 ns_St_2_Wait;
  int beaconcount_St_2_Wait;
  int flg_St_2_Wait;
  int cnt_St_2_Wait;
  int nr_St_2_Increment;
  Line_follower__st_2 ns_St_2_Increment;
  int beaconcount_St_2_Increment;
  int flg_St_2_Increment;
  int cnt_St_2_Increment;
  int nr_St_2_Ready;
  Line_follower__st_2 ns_St_2_Ready;
  int beaconcount_St_2_Ready;
  int flg_St_2_Ready;
  int cnt_St_2_Ready;
  Line_follower__st_2 ck_3;
  Line_follower__st_2 s;
  Line_follower__st_2 ns;
  int r;
  int nr;
  int cnt;
  int flg;
  int beaconcount;
  switch (self->ck) {
    case Line_follower__St_2_Ready:
      v_227 = sen[3];
      v_228 = (v_227<500.000000);
      v_224 = sen[2];
      v_221 = sen[1];
      v_225 = (v_224<750.000000);
      v_222 = (v_221<750.000000);
      v_220 = (second>23);
      v_223 = (v_220&&v_222);
      v_226 = (v_223&&v_225);
      v_229 = (v_226&&v_228);
      if (v_229) {
        r_St_2_Ready = false;
        s_St_2_Ready = Line_follower__St_2_Increment;
      } else {
        r_St_2_Ready = self->pnr;
        s_St_2_Ready = Line_follower__St_2_Ready;
      };
      s = s_St_2_Ready;
      r = r_St_2_Ready;
      break;
    case Line_follower__St_2_Increment:
      r_St_2_Increment = self->pnr;
      s_St_2_Increment = Line_follower__St_2_Increment;
      s = s_St_2_Increment;
      r = r_St_2_Increment;
      break;
    case Line_follower__St_2_Wait:
      v = (self->beaconcount_1>1);
      if (v) {
        r_St_2_Wait = false;
        s_St_2_Wait = Line_follower__St_2_Ready;
      } else {
        r_St_2_Wait = self->pnr;
        s_St_2_Wait = Line_follower__St_2_Wait;
      };
      s = s_St_2_Wait;
      r = r_St_2_Wait;
      break;
    default:
      break;
  };
  ck_3 = s;
  switch (ck_3) {
    case Line_follower__St_2_Ready:
      beaconcount_St_2_Ready = 0;
      flg_St_2_Ready = false;
      cnt_St_2_Ready = self->cnt_2;
      nr_St_2_Ready = false;
      ns_St_2_Ready = Line_follower__St_2_Ready;
      cnt = cnt_St_2_Ready;
      flg = flg_St_2_Ready;
      beaconcount = beaconcount_St_2_Ready;
      ns = ns_St_2_Ready;
      nr = nr_St_2_Ready;
      break;
    case Line_follower__St_2_Increment:
      beaconcount_St_2_Increment = 0;
      flg_St_2_Increment = true;
      cnt_St_2_Increment = (self->cnt_2+1);
      if (true) {
        nr_St_2_Increment = true;
      } else {
        nr_St_2_Increment = false;
      };
      if (true) {
        ns_St_2_Increment = Line_follower__St_2_Wait;
      } else {
        ns_St_2_Increment = Line_follower__St_2_Increment;
      };
      cnt = cnt_St_2_Increment;
      flg = flg_St_2_Increment;
      beaconcount = beaconcount_St_2_Increment;
      ns = ns_St_2_Increment;
      nr = nr_St_2_Increment;
      break;
    case Line_follower__St_2_Wait:
      flg_St_2_Wait = true;
      cnt_St_2_Wait = self->cnt_2;
      beaconcount_St_2_Wait = (self->beaconcount_1+beacon);
      nr_St_2_Wait = false;
      ns_St_2_Wait = Line_follower__St_2_Wait;
      cnt = cnt_St_2_Wait;
      flg = flg_St_2_Wait;
      beaconcount = beaconcount_St_2_Wait;
      ns = ns_St_2_Wait;
      nr = nr_St_2_Wait;
      break;
    default:
      break;
  };
  _out->flag = flg;
  _out->count = cnt;
  self->beaconcount_1 = beaconcount;
  self->flg_1 = flg;
  self->cnt_2 = cnt;
  self->pnr = nr;
  self->ck = ns;;
}

void Line_follower__check_step(float sen[5], int second,
                               Line_follower__check_out* _out) {
  
  int v_240;
  int v_239;
  float v_238;
  int v_237;
  int v_236;
  int v_235;
  float v_234;
  int v_233;
  int v_232;
  float v_231;
  int v_230;
  float v;
  v_238 = sen[0];
  v_239 = (v_238>900.000000);
  v_237 = (second>23);
  v_240 = (v_237&&v_239);
  if (v_240) {
    _out->black_switch = true;
  } else {
    _out->black_switch = false;
  };
  v_234 = sen[4];
  v_235 = (v_234<700.000000);
  v_231 = sen[2];
  v = sen[0];
  v_232 = (v_231>900.000000);
  v_230 = (v<700.000000);
  v_233 = (v_230&&v_232);
  v_236 = (v_233&&v_235);
  if (v_236) {
    _out->white_switch = true;
  } else {
    _out->white_switch = false;
  };;
}

void Line_follower__main_reset(Line_follower__main_mem* self) {
  Line_follower__counter_reset(&self->counter);
  Line_follower__calculatePID_reset(&self->calculatePID);
  Line_follower__calculateMotor2_reset(&self->calculateMotor2);
  Line_follower__calculateMotor1_reset(&self->calculateMotor1);
  self->pnr = false;
  self->ck = Line_follower__St_3_Whiteline;
}

void Line_follower__main_step(int sen0, int sen1, int sen2, int sen3,
                              int sen4, int second, int beacon,
                              Line_follower__main_out* _out,
                              Line_follower__main_mem* self) {
  Mc_ext__float_of_int_out Mc_ext__float_of_int_out_st;
  Line_follower__calculatePID_out Line_follower__calculatePID_out_st;
  Line_follower__check_out Line_follower__check_out_st;
  Line_follower__calculateMotor1_out Line_follower__calculateMotor1_out_st;
  Line_follower__calculateMotor2_out Line_follower__calculateMotor2_out_st;
  Line_follower__calculateError_out Line_follower__calculateError_out_st;
  Line_follower__counter_out Line_follower__counter_out_st;
  
  int r_St_3_Blackline;
  Line_follower__st_3 s_St_3_Blackline;
  int r_St_3_Whiteline;
  Line_follower__st_3 s_St_3_Whiteline;
  int r_1;
  int r_2;
  int nr_St_3_Blackline;
  Line_follower__st_3 ns_St_3_Blackline;
  float weights_St_3_Blackline[4];
  int dir_St_3_Blackline;
  int v_r_St_3_Blackline;
  int v_l_St_3_Blackline;
  int nr_St_3_Whiteline;
  Line_follower__st_3 ns_St_3_Whiteline;
  float weights_St_3_Whiteline[4];
  int dir_St_3_Whiteline;
  int v_r_St_3_Whiteline;
  int v_l_St_3_Whiteline;
  Line_follower__st_3 ck_4;
  float v_244;
  float v_243;
  float v_242;
  float v_241;
  float v;
  Line_follower__st_3 s;
  Line_follower__st_3 ns;
  int r;
  int nr;
  float sen[5];
  float weights[4];
  float error;
  int white_switch;
  int black_switch;
  int flag;
  int count;
  Mc_ext__float_of_int_step(sen4, &Mc_ext__float_of_int_out_st);
  v_244 = Mc_ext__float_of_int_out_st.o;
  Mc_ext__float_of_int_step(sen3, &Mc_ext__float_of_int_out_st);
  v_243 = Mc_ext__float_of_int_out_st.o;
  Mc_ext__float_of_int_step(sen2, &Mc_ext__float_of_int_out_st);
  v_242 = Mc_ext__float_of_int_out_st.o;
  Mc_ext__float_of_int_step(sen1, &Mc_ext__float_of_int_out_st);
  v_241 = Mc_ext__float_of_int_out_st.o;
  Mc_ext__float_of_int_step(sen0, &Mc_ext__float_of_int_out_st);
  v = Mc_ext__float_of_int_out_st.o;
  switch (self->ck) {
    case Line_follower__St_3_Blackline:
      r_St_3_Blackline = self->pnr;
      s_St_3_Blackline = Line_follower__St_3_Blackline;
      break;
    default:
      break;
  };
  sen[0] = v;
  sen[1] = v_241;
  sen[2] = v_242;
  sen[3] = v_243;
  sen[4] = v_244;
  Line_follower__counter_step(sen, beacon, second,
                              &Line_follower__counter_out_st, &self->counter);
  count = Line_follower__counter_out_st.count;
  flag = Line_follower__counter_out_st.flag;
  _out->cnt = count;
  Line_follower__check_step(sen, second, &Line_follower__check_out_st);
  white_switch = Line_follower__check_out_st.white_switch;
  black_switch = Line_follower__check_out_st.black_switch;
  switch (self->ck) {
    case Line_follower__St_3_Whiteline:
      if (black_switch) {
        r_St_3_Whiteline = true;
        s_St_3_Whiteline = Line_follower__St_3_Blackline;
      } else {
        r_St_3_Whiteline = self->pnr;
        s_St_3_Whiteline = Line_follower__St_3_Whiteline;
      };
      s = s_St_3_Whiteline;
      r = r_St_3_Whiteline;
      break;
    case Line_follower__St_3_Blackline:
      s = s_St_3_Blackline;
      r = r_St_3_Blackline;
      break;
    default:
      break;
  };
  ck_4 = s;
  switch (ck_4) {
    case Line_follower__St_3_Whiteline:
      nr_St_3_Whiteline = false;
      ns_St_3_Whiteline = Line_follower__St_3_Whiteline;
      r_2 = r;
      ns = ns_St_3_Whiteline;
      nr = nr_St_3_Whiteline;
      weights_St_3_Whiteline[0] = 0.400000;
      weights_St_3_Whiteline[1] = 0.300000;
      weights_St_3_Whiteline[2] = 0.426000;
      weights_St_3_Whiteline[3] = 0.400000;
      {
        int _4;
        for (_4 = 0; _4 < 4; ++_4) {
          weights[_4] = weights_St_3_Whiteline[_4];
        }
      };
      break;
    case Line_follower__St_3_Blackline:
      nr_St_3_Blackline = false;
      ns_St_3_Blackline = Line_follower__St_3_Blackline;
      r_1 = r;
      ns = ns_St_3_Blackline;
      nr = nr_St_3_Blackline;
      weights_St_3_Blackline[0] = 0.350000;
      weights_St_3_Blackline[1] = 0.280000;
      weights_St_3_Blackline[2] = 0.405000;
      weights_St_3_Blackline[3] = 0.350000;
      {
        int _5;
        for (_5 = 0; _5 < 4; ++_5) {
          weights[_5] = weights_St_3_Blackline[_5];
        }
      };
      break;
    default:
      break;
  };
  Line_follower__calculateError_step(sen, weights,
                                     &Line_follower__calculateError_out_st);
  error = Line_follower__calculateError_out_st.error;
  Line_follower__calculatePID_step(error,
                                   &Line_follower__calculatePID_out_st,
                                   &self->calculatePID);
  _out->pidValue = Line_follower__calculatePID_out_st.pidValue;
  switch (ck_4) {
    case Line_follower__St_3_Blackline:
      if (r_1) {
        Line_follower__calculateMotor2_reset(&self->calculateMotor2);
      };
      Line_follower__calculateMotor2_step(sen, _out->pidValue, count, flag,
                                          &Line_follower__calculateMotor2_out_st,
                                          &self->calculateMotor2);
      v_l_St_3_Blackline = Line_follower__calculateMotor2_out_st.v_l;
      v_r_St_3_Blackline = Line_follower__calculateMotor2_out_st.v_r;
      dir_St_3_Blackline = Line_follower__calculateMotor2_out_st.dir;
      _out->v_l = v_l_St_3_Blackline;
      _out->v_r = v_r_St_3_Blackline;
      _out->dir = dir_St_3_Blackline;
      break;
    case Line_follower__St_3_Whiteline:
      if (r_2) {
        Line_follower__calculateMotor1_reset(&self->calculateMotor1);
      };
      Line_follower__calculateMotor1_step(_out->pidValue,
                                          &Line_follower__calculateMotor1_out_st,
                                          &self->calculateMotor1);
      v_l_St_3_Whiteline = Line_follower__calculateMotor1_out_st.v_l;
      v_r_St_3_Whiteline = Line_follower__calculateMotor1_out_st.v_r;
      dir_St_3_Whiteline = Line_follower__calculateMotor1_out_st.dir;
      _out->v_l = v_l_St_3_Whiteline;
      _out->v_r = v_r_St_3_Whiteline;
      _out->dir = dir_St_3_Whiteline;
      break;
    default:
      break;
  };
  self->pnr = nr;
  self->ck = ns;;
}

