#include <iostream>
#include <cmath>

int main()
{
    double a=0, b=0, c=0, root1, root2, discriminant, real_part, imaginary_part;
    std::cout << "Insert a value for a: " << std::endl;
    std::cin >> a;
    std::cout << "Insert a value for b: " << std::endl;
    std::cin >> b;
    std::cout << "Insert a value for c: " << std::endl;
    std::cin >> c;

    discriminant = b*b - 4*a*c;
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);
        std::cout << "Root 1 is :" << root1 << std::endl;
        std::cout << "Root 2 is :" << root2 << std::endl;
    } else if (discriminant == 0) {
        root1 = (-b + sqrt(discriminant)) / (2*a);
        std::cout << "Root 1 is :" << root1 << std::endl;
        std::cout << "Root 2 is :" << root1 << std::endl;
    } else {
        real_part = -b/(2*a);
        imaginary_part = sqrt(-discriminant) / (2*a);
        std::cout << "Root 1 is :" << real_part << " + " << imaginary_part << "i" << std::endl;
        std::cout << "Root 2 is :" << real_part << " - " <<      imaginary_part << "i" << std::endl;
    }
    
    return 0;

}

