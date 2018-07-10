#include <cstdlib>
#include <iostream>
#include <time.h>

double compute_pi(int N)
{ 
    std::srand( std::time(NULL) ); //Randomize seed initialization
    int count = 0;
    for (int i=0; i<N; ++i){
        double x = (double)std::rand() / RAND_MAX;
        double y = (double)std::rand() / RAND_MAX;
        if (x * x + y * y < 1){
            count += 1;
        }
    }
    return (double)4 * count / N;
}


int main()
{
    int N;
    std::cout << "Enter the number of Monte Carlo simulations: ";
    std::cin >> N;
    double pi_estimate = compute_pi(N);
    std::cout << "pi = " << pi_estimate << std::endl;;
    return 0;
}
