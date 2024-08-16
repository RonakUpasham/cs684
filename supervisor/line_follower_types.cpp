/* --- Generated the 11/4/2024 at 19:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line_follower_types.h"

Line_follower__st_3 Line_follower__st_3_of_string(char* s) {
  if ((strcmp(s, "St_3_Whiteline")==0)) {
    return Line_follower__St_3_Whiteline;
  };
  if ((strcmp(s, "St_3_Blackline")==0)) {
    return Line_follower__St_3_Blackline;
  };
}

char* string_of_Line_follower__st_3(Line_follower__st_3 x, char* buf) {
  switch (x) {
    case Line_follower__St_3_Whiteline:
      strcpy(buf, "St_3_Whiteline");
      break;
    case Line_follower__St_3_Blackline:
      strcpy(buf, "St_3_Blackline");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st_2 Line_follower__st_2_of_string(char* s) {
  if ((strcmp(s, "St_2_Wait")==0)) {
    return Line_follower__St_2_Wait;
  };
  if ((strcmp(s, "St_2_Ready")==0)) {
    return Line_follower__St_2_Ready;
  };
  if ((strcmp(s, "St_2_Increment")==0)) {
    return Line_follower__St_2_Increment;
  };
}

char* string_of_Line_follower__st_2(Line_follower__st_2 x, char* buf) {
  switch (x) {
    case Line_follower__St_2_Wait:
      strcpy(buf, "St_2_Wait");
      break;
    case Line_follower__St_2_Ready:
      strcpy(buf, "St_2_Ready");
      break;
    case Line_follower__St_2_Increment:
      strcpy(buf, "St_2_Increment");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st_1 Line_follower__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_Noderight")==0)) {
    return Line_follower__St_1_Noderight;
  };
  if ((strcmp(s, "St_1_Nodeone")==0)) {
    return Line_follower__St_1_Nodeone;
  };
  if ((strcmp(s, "St_1_Nodeleft")==0)) {
    return Line_follower__St_1_Nodeleft;
  };
  if ((strcmp(s, "St_1_Forward")==0)) {
    return Line_follower__St_1_Forward;
  };
}

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf) {
  switch (x) {
    case Line_follower__St_1_Noderight:
      strcpy(buf, "St_1_Noderight");
      break;
    case Line_follower__St_1_Nodeone:
      strcpy(buf, "St_1_Nodeone");
      break;
    case Line_follower__St_1_Nodeleft:
      strcpy(buf, "St_1_Nodeleft");
      break;
    case Line_follower__St_1_Forward:
      strcpy(buf, "St_1_Forward");
      break;
    default:
      break;
  };
  return buf;
}

Line_follower__st Line_follower__st_of_string(char* s) {
  if ((strcmp(s, "St_Hardright")==0)) {
    return Line_follower__St_Hardright;
  };
  if ((strcmp(s, "St_Hardleft")==0)) {
    return Line_follower__St_Hardleft;
  };
  if ((strcmp(s, "St_Forward")==0)) {
    return Line_follower__St_Forward;
  };
}

char* string_of_Line_follower__st(Line_follower__st x, char* buf) {
  switch (x) {
    case Line_follower__St_Hardright:
      strcpy(buf, "St_Hardright");
      break;
    case Line_follower__St_Hardleft:
      strcpy(buf, "St_Hardleft");
      break;
    case Line_follower__St_Forward:
      strcpy(buf, "St_Forward");
      break;
    default:
      break;
  };
  return buf;
}

