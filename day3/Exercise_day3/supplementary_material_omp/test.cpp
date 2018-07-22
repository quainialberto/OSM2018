#include <stdio.h>

int main() {
     double x=.9, y=.8;
     double t;
     int z;

     z=x*x+y*y;
     t=x*x+y*y;
     printf("z should be 1: %i\n", z);
     x=.4;
     z=x*x+y*y;
     
     printf("z should be 0:  %i\n", z);

     return 0;
 }
