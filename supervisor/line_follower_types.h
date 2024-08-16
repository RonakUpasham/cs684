/* --- Generated the 11/4/2024 at 19:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts line_follower.ept --- */

#ifndef LINE_FOLLOWER_TYPES_H
#define LINE_FOLLOWER_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
#include "mc_ext_types.h"
typedef enum {
  Line_follower__St_3_Whiteline,
  Line_follower__St_3_Blackline
} Line_follower__st_3;

Line_follower__st_3 Line_follower__st_3_of_string(char* s);

char* string_of_Line_follower__st_3(Line_follower__st_3 x, char* buf);

typedef enum {
  Line_follower__St_2_Wait,
  Line_follower__St_2_Ready,
  Line_follower__St_2_Increment
} Line_follower__st_2;

Line_follower__st_2 Line_follower__st_2_of_string(char* s);

char* string_of_Line_follower__st_2(Line_follower__st_2 x, char* buf);

typedef enum {
  Line_follower__St_1_Noderight,
  Line_follower__St_1_Nodeone,
  Line_follower__St_1_Nodeleft,
  Line_follower__St_1_Forward
} Line_follower__st_1;

Line_follower__st_1 Line_follower__st_1_of_string(char* s);

char* string_of_Line_follower__st_1(Line_follower__st_1 x, char* buf);

typedef enum {
  Line_follower__St_Hardright,
  Line_follower__St_Hardleft,
  Line_follower__St_Forward
} Line_follower__st;

Line_follower__st Line_follower__st_of_string(char* s);

char* string_of_Line_follower__st(Line_follower__st x, char* buf);

static const float Line_follower__kp = 0.300000;

static const float Line_follower__kd = 0.300000;

static const float Line_follower__ki = 0.000000;

static const float Line_follower__white_weights[4] = {0.400000, 0.300000,
                                                      0.426000, 0.400000};

static const float Line_follower__t_small_pos = 20.000000;

static const float Line_follower__t_small_neg = -20.000000;

static const float Line_follower__t_large_pos = 70.000000;

static const float Line_follower__t_large_neg = -70.000000;

static const float Line_follower__black_weights[4] = {0.350000, 0.280000,
                                                      0.405000, 0.350000};

static const float Line_follower__t_small_pos2 = 8.000000;

static const float Line_follower__t_small_neg2 = -8.000000;

#endif // LINE_FOLLOWER_TYPES_H
