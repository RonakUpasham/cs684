/* --- Generated the 17/4/2024 at 15:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts remote_control.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

Remote_control__main_mem mem;
int main(int argc, char** argv) {
  int step_c;
  int step_max;
  int diR;
  Remote_control__main_out _res;
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  Remote_control__main_reset(&mem);
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
    
    if ((scanf("%d", &diR)==EOF)) {
      return 0;
    };;
    Remote_control__main_step(diR, &_res, &mem);
    printf("%d\n", _res.v_l);
    printf("%d\n", _res.v_r);
    printf("%d\n", _res.dir);
    fflush(stdout);
  };
  return 0;
}

