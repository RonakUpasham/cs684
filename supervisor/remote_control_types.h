/* --- Generated the 17/4/2024 at 15:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts remote_control.ept --- */

#ifndef REMOTE_CONTROL_TYPES_H
#define REMOTE_CONTROL_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Remote_control__St_1_Stopped,
  Remote_control__St_1_Run
} Remote_control__st_1;

Remote_control__st_1 Remote_control__st_1_of_string(char* s);

char* string_of_Remote_control__st_1(Remote_control__st_1 x, char* buf);

typedef enum {
  Remote_control__St_Up,
  Remote_control__St_Right,
  Remote_control__St_Left,
  Remote_control__St_Idle,
  Remote_control__St_Down
} Remote_control__st;

Remote_control__st Remote_control__st_of_string(char* s);

char* string_of_Remote_control__st(Remote_control__st x, char* buf);

#endif // REMOTE_CONTROL_TYPES_H
