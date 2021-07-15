#include <iostream>
#include "src/Tools/Vector.h"
#include "src/Tools/Entity.h"
#include "src/Tools/Ray.h"

int main() {
    std::cout << "===============Start : Vector===============" << std::endl;
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
    std::cout << "===============End : Vector===============" << std::endl;
    std::cout << "===============Start : Ray===============" << std::endl;
    Ray ray(1, 2, 3, 4, 5, 6);
    std::cout << ray << std::endl;
    std::cout << "===============Start : Entity===============" << std::endl;
    Entity e;
    std::cout << v << std::endl;
    std::cout << e << std::endl;
    e.translate(v);
    e.rotateX(12);
    e.rotateY(14);
    e.rotateZ(16);
    e.scale(3);
    std::cout << e << std::endl;
    e.rotate(v);
    std::cout << e << std::endl;
    std::cout << "===============End : Entity===============" << std::endl;
    std::cout << "===============Start : Matrix===============" << std::endl;
    std::array<float, 16> tab {1,0,2,4,0,1,3,2,2,-1,0,3,4,-1,3,9};
    Matrix matrix(tab);
    std::cout << matrix <<std::endl;
    Matrix inv = matrix.inverse();
    std::cout << inv <<std::endl;
}
