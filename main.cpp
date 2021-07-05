#include <iostream>
#include "src/Tools/Vector.h"

int main() {
    Vector v(1, 2, 3);
    std::cout << v << std::endl;
    Vector u(5, 6, 7);
    Vector result =  u + v;
    std::cout << v << std::endl;




}
