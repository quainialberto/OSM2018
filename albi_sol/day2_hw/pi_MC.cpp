#include <cstdlib>
#include <stdio.h>
#include <time.h>

int main (void)
{
    clock_t stime {-clock()};
    const unsigned max_iter = int(1e8);
    srand( time(NULL) );
    unsigned count {0};
    double x {0.0}, y {0.0};
    
    for (unsigned i=0; i<max_iter; ++i) 
    {
        x = (double)rand() / RAND_MAX; 
        y = (double)rand() / RAND_MAX;
        if ( x*x + y*y < 1 ) ++count;
    }
    
    const double pi = (double)4.0 * count / max_iter;

    stime += clock();
    printf("Number of MC iterations: %u\n", max_iter);
    printf("Pi is approximately: %lf\n", pi);
    printf("Execution time: %lfs\n", (double)stime / CLOCKS_PER_SEC );
    
    return 0;
}
