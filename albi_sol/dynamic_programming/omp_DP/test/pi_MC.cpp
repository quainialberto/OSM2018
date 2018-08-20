#include <cstdlib>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

double compute_pi(int N)
{
    srand( time(NULL) ); //Randomize seed initialization
    int count = 0;
    for (int i=0; i<N; ++i)
    {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x * x + y * y < 1)
        {
            count += 1;
        }
    }
    
    return (double)4 * count / N;
}

int main ()
{
    clock_t tStart; 
    tStart = clock();   
    for (int n=0; n<7; n++)
    {
        int N = 100 * pow(10, n);
        double pi_estimate = compute_pi(N);
        cout << "------------------------------" << endl;
        cout << "Number of MC iterations: " << N << endl;
        cout << "Pi is approximately: " << pi_estimate << endl;
    }
    
    cout << "Time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
    return 0;
}
