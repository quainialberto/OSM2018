#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main()
{
    const int niter = 1e8;
    double x=0., y=0.;
    int count=0;
    double pi=0.;
    
    //main loop
    #pragma omp parallel private(x, y) 
    {
    srand( (omp_get_thread_num()+1)*2 );
        
    #pragma omp for reduction(+:count)
    for (int i=0; i<niter; ++i){
        //get random points
        x = (double)random()/RAND_MAX;
        y = (double)random()/RAND_MAX;
        //check to see if point is in unit circle
        if (x*x + y*y<=1)
        {
            ++count;
        }
    }
    }
    
    pi = ((double)count/(double)niter)*4.0;
    printf("Pi: %f\n", pi);
    return 0;
}
