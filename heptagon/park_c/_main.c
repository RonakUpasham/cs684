/* --- Generated the 11/4/2024 at 19:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. feb. 12 22:46:10 CET 2024) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts park.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

Park__main_mem mem;
int main(int argc, char** argv) {
  int step_c;
  int step_max;
  int sen0;
  int sen1;
  int sen2;
  int sen3;
  int sen4;
  int irSen1;
  int irSen2;
  int irSen3;
  int irSen4;
  int beacon;
  Park__main_out _res;
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  Park__main_reset(&mem);
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
    
    if ((scanf("%d", &sen0)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen1)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen2)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen3)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &sen4)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &irSen1)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &irSen2)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &irSen3)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &irSen4)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &beacon)==EOF)) {
      return 0;
    };;
    Park__main_step(sen0, sen1, sen2, sen3, sen4, irSen1, irSen2, irSen3,
                    irSen4, beacon, &_res, &mem);
    printf("%d\n", _res.v_l);
    printf("%d\n", _res.v_r);
    printf("%d\n", _res.dir);
    fflush(stdout);
  };
  return 0;
}

