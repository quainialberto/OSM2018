#include <stdio.h>

int main (void)
{
    const double f = 0.4 / 100;
    const unsigned short p = 100;
    const double speed = 1.0 / (f + (1.0 - f) / double(p));
    printf("Number of CPU: %u\n", p);
    printf("Serial code fraction: %lf\n", f);
    printf("The speed-up is: %lf", speed);

    return 0;
}
