/* --- Generated the 17/4/2024 at 15:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts remote_control.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "remote_control_types.h"

Remote_control__st_1 Remote_control__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_Stopped")==0)) {
    return Remote_control__St_1_Stopped;
  };
  if ((strcmp(s, "St_1_Run")==0)) {
    return Remote_control__St_1_Run;
  };
}

char* string_of_Remote_control__st_1(Remote_control__st_1 x, char* buf) {
  switch (x) {
    case Remote_control__St_1_Stopped:
      strcpy(buf, "St_1_Stopped");
      break;
    case Remote_control__St_1_Run:
      strcpy(buf, "St_1_Run");
      break;
    default:
      break;
  };
  return buf;
}

Remote_control__st Remote_control__st_of_string(char* s) {
  if ((strcmp(s, "St_Up")==0)) {
    return Remote_control__St_Up;
  };
  if ((strcmp(s, "St_Right")==0)) {
    return Remote_control__St_Right;
  };
  if ((strcmp(s, "St_Left")==0)) {
    return Remote_control__St_Left;
  };
  if ((strcmp(s, "St_Idle")==0)) {
    return Remote_control__St_Idle;
  };
  if ((strcmp(s, "St_Down")==0)) {
    return Remote_control__St_Down;
  };
}

char* string_of_Remote_control__st(Remote_control__st x, char* buf) {
  switch (x) {
    case Remote_control__St_Up:
      strcpy(buf, "St_Up");
      break;
    case Remote_control__St_Right:
      strcpy(buf, "St_Right");
      break;
    case Remote_control__St_Left:
      strcpy(buf, "St_Left");
      break;
    case Remote_control__St_Idle:
      strcpy(buf, "St_Idle");
      break;
    case Remote_control__St_Down:
      strcpy(buf, "St_Down");
      break;
    default:
      break;
  };
  return buf;
}

