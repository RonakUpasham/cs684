/* --- Generated the 11/4/2024 at 19:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts park.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "park_types.h"

Park__st_1 Park__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_Turn")==0)) {
    return Park__St_1_Turn;
  };
  if ((strcmp(s, "St_1_Parking2")==0)) {
    return Park__St_1_Parking2;
  };
  if ((strcmp(s, "St_1_Parking1")==0)) {
    return Park__St_1_Parking1;
  };
  if ((strcmp(s, "St_1_Forward")==0)) {
    return Park__St_1_Forward;
  };
}

char* string_of_Park__st_1(Park__st_1 x, char* buf) {
  switch (x) {
    case Park__St_1_Turn:
      strcpy(buf, "St_1_Turn");
      break;
    case Park__St_1_Parking2:
      strcpy(buf, "St_1_Parking2");
      break;
    case Park__St_1_Parking1:
      strcpy(buf, "St_1_Parking1");
      break;
    case Park__St_1_Forward:
      strcpy(buf, "St_1_Forward");
      break;
    default:
      break;
  };
  return buf;
}

Park__st Park__st_of_string(char* s) {
  if ((strcmp(s, "St_Turn")==0)) {
    return Park__St_Turn;
  };
  if ((strcmp(s, "St_Stationary")==0)) {
    return Park__St_Stationary;
  };
  if ((strcmp(s, "St_Forward")==0)) {
    return Park__St_Forward;
  };
}

char* string_of_Park__st(Park__st x, char* buf) {
  switch (x) {
    case Park__St_Turn:
      strcpy(buf, "St_Turn");
      break;
    case Park__St_Stationary:
      strcpy(buf, "St_Stationary");
      break;
    case Park__St_Forward:
      strcpy(buf, "St_Forward");
      break;
    default:
      break;
  };
  return buf;
}

