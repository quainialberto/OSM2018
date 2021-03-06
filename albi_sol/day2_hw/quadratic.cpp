#include <stdio.h>
#include <complex>
#include <cmath>

int main (void)
{   
    printf("Quadratic Equation Solver\n");
    double a {0.0}, b {0.0}, c {0.0};
    printf("Insert a value for 'a' (double, e.g. 3.5): ");
    scanf ("%lf",&a);
    printf("Insert a value for 'b' (double, e.g. 3.5): ");
    scanf ("%lf",&b);
    printf("Insert a value for 'c' (double, e.g. 3.5): ");
    scanf ("%lf",&c);
    
    std::complex<double> aa (a, 0.0);
    std::complex<double> bb (b, 0.0);
    std::complex<double> cc (c, 0.0);
    std::complex<double> discriminant = sqrt( pow(bb, 2) - 4.0*aa*cc );
    std::complex<double> root1 = (-bb + discriminant) / (2.0*aa);
    std::complex<double> root2 = (-bb - discriminant) / (2.0*aa);
    printf("Root 1 is: %f + %fi\n", real(root1), imag(root1));
    printf("Root 2 is: %f + %fi\n", real(root2), imag(root2));
    
    return 0;
}

