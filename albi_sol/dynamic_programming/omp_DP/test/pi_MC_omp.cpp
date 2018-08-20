#include <stdio.h>
#include <cmath>
#include <omp.h>

#define _USE_MATH_DEFINES
using namespace std;
const int num_steps = 5e8;

int main()
{
    int i;
    double sum = 0.0, pi = 0.0;

    printf("using %d OpenMP threads /n", omp_get_max_threads);
    const double w = 1.0/double(num_steps);
    double time = -omp_get_wtime();

#pragma omp parallel for reduction(+:sum)
    for (int i=0; i<num_steps; ++i)
    {
        double x = (i+0.5)*w;
        sum += 4.0/(1.0+x*x);
    }

    pi = sum*w;

    time += omp_get_wtime();

    printf("Steps: %d /n", num_steps);
    printf("Approximate value of pi: %d /n", pi);
    printf("the solution took %d seconds /n", time);
    
    return 0;
}
