#include <stdio.h>
#include <omp.h>

int main (void)
{
    double time {-omp_get_wtime()};
    const unsigned num_steps {int(1e8)};
    const double step {1.0/double(num_steps)};
    double x {0.0}, pi {0.0};
    
    #pragma omp parallel for reduction(+:sum)
    for (unsigned i=0; i<num_steps; i++) 
    {
        x = (double(i) + 0.5) * step;
        pi += 4.0 / (1.0 + x*x);
        //printf("Iteration %d Thread %d\n", i, omp_get_thread_num());
    }

    pi *= step;
    time += omp_get_wtime();

    printf("Pi is approximately: %lf\n", pi);
    printf("Execution time: %lf\n", time);
    
    return 0;
}
