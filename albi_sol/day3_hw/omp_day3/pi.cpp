#include <cmath>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES

#define RNG_MOD 0x80000000
int state;

int rng_int(void);
double rng_doub(double range);

int main() {
    int i, count, niter;
    double x, y, pi;
    niter = 1e9;
    count = 0;
    double stime = -omp_get_wtime();

    #pragma omp threadprivate(state)
    #pragma omp parallel private(x, y) reduction(+:count) 
    {
        state = 25234 + 17 * omp_get_thread_num();
        #pragma omp for
        for (i = 0; i <= niter; i++) {
            x = (double)rng_doub(1.0);
            y = (double)rng_doub(1.0);
            if (x*x + y*y <= 1) count++;
        }
    }
    
    pi = 4.*count / niter;
    stime += omp_get_wtime();
    
    printf("Number of iterations: %i\n", niter);
    printf("Approximate pi: %f\n", pi);
    printf("Execution time: %f\n", stime);
    printf("Relative error: %E\n", fabs(M_PI-pi)/M_PI);
    return 0;
}

int rng_int(void) {
// & 0x7fffffff is equivalent to modulo with RNG_MOD = 2^31
return (state = (state * 1103515245 + 12345) & 0x7fffffff);
}

double rng_doub(double range) {
return ((double)rng_int()) / (((double)RNG_MOD)/range);
}
