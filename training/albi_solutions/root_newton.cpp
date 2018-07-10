#include <iostream>
#include <cmath>

int main()
{
    double x_old=0, x_new=0, tol=0;
    int N=0, i=0;
    std::cout << "Insert an initial guess x0: ";
    std::cin >> x_old;
    std::cout << "Insert the maximal number of iterations: ";
    std::cin >> N;
    std::cout << "Insert a tolerance parameter: ";
    std::cin >> tol;
    double dist = 0;

    do {
        x_new = x_old + (cos(x_old) - x_old) / (sin(x_old) + 1);
        dist = abs(x_new - x_old);
        x_old = x_new;
        ++i;
    } while (i < N && dist > tol);
    
    std::cout << "The root of f(x)=cos(x)-x is: " << x_new << std::endl;
    return 0;

}
