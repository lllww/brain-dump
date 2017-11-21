#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



void signal_handler (int signo) {
    if(signo == SIGFPE) {
      std::cout << "Caught FPE\n";
    }
}

int main (void) {
  signal(SIGFPE,(*signal_handler));

  int b = 1;
  int c = 0;
  int d = b/c;
  fprintf(stderr,"d number is %d\n",d);
  return 0;
}