#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    printf("Root finder for cos(x)-x\n");
    printf("------------------------\n");
    double x_old=0.0, x_new=0.0, tol=0.0;
    int N=0, i=0;
    printf("Insert an initial guess x0: ");
    scanf("%lf", &x_old);
    printf("Insert the maximal number of iterations: ");
    scanf("%i", &N);
    printf("Insert a tolerance parameter: ");
    scanf("%lf", &tol);
    double dist = 0.0;

    do {
        x_new = x_old + (cos(x_old) - x_old) / (sin(x_old) + 1);
        dist = abs(x_new - x_old);
        x_old = x_new;
        ++i;
    } while (i < N && dist > tol);
    
    printf("The root of f(x)=cos(x)-x is: %lf", x_new);
    return 0;

}
