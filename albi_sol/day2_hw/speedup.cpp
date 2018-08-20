#include <iostream>

int main()
{
    double f = 0.4 / 100;
    double p = 100;
    double speed = 1 / (f + (1 - f) / p);
    std::cout << "Number of CPU: " << p << std::endl;
    std::cout << "Serial code fraction: " << f << std::endl;
    std::cout << "The speed-up is: " << speed  << std::endl;

    return 0;
}
