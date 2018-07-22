#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define _USE_MATH_DEFINES

using namespace std;

int main()
{   
    const int niter = 1e7;
    srand( time(NULL) );
    int i, count=0;
    double x=0., y=0.;
    //int z=0;
    //double x[niter], y[niter];
    int z[niter];
    double stime = -omp_get_wtime();

    for (i=0; i<niter; ++i) {
        x=(double)random()/RAND_MAX;
        y=(double)random()/RAND_MAX;
       z[i]=x*x+y*y; 
    }
    #pragma omp parallel //private(x,y,z) 
    {
    #pragma omp for reduction(+:count)
    for (i=0; i<niter; ++i) {
        //get random points
        //x = (double)random()/RAND_MAX;
        //y = (double)random()/RAND_MAX;
        //z = x*x+y*y;
        //count += 1 - 1*z[i];
        if (z[i]<1) ++count;
    }
    }
    
    stime += omp_get_wtime();
    double pi = (double) 4.0*count/niter;
    printf("Using %i threads\n", omp_get_max_threads());   
    printf("Pi is approximately: %f\n", pi);
    printf("Relative error: %E\n", fabs(M_PI-pi)/M_PI);
    printf("Iterations took: %f\n", stime);
    
    return 0;
}
