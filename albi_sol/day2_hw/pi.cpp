#include <stdio.h>
#include <time.h>

int main (void)
{
    clock_t stime {-clock()};
    const unsigned num_steps {int(1e8)}; 
    const double step {1.0/double(num_steps)};
    double x {0.0}, pi {0.0};

    for (unsigned i=0; i<num_steps; ++i)
    {
        x = (i + 0.5)*step;
        pi += 4.0/(1.0 + x*x);
    }
    pi *= step;
    
    stime += clock();
    printf( "Pi is approximately: %lf\n", pi );
    printf( "Execution time: %lfs\n", (double)stime/CLOCKS_PER_SEC );
    
    return 0;
}
