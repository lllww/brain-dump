#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*
    
    This program will keep outputing "Caught FPE".

    Because we have replaced the default SIGFPE handler, which will kill the process.


    When FPE is detected, an interrupt is sent to CPU and corresponding ISR is invoked
    which will send signal to our process thus invoking our SIGFPE handler in our process context.

    Therefore, the pipeline looks like:

    FPE -> Interrupt -> ISR -> SIGFPE -> SIGFPE Handler

*/
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