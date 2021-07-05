#include <iostream>
#include "src/Tools/Vector.h"

int main() {
    Vector v(1, 2, 3);
    std::cout << v << std::endl;
    Vector u(5, 6, 7);
    Vector result = u + v;
    std::cout << result << std::endl;
    result = -v;
    std::cout << result << std::endl;
    result = u - v;
    std::cout << result << std::endl;
    float calcul = 2;
    result = v * calcul;
    std::cout << result << std::endl;
    result = v / calcul;
    std::cout << result << std::endl;
}
