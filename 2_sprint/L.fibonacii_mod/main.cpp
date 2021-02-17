#include <iostream>
#include <cmath>

unsigned int fibonacci(unsigned int number, unsigned int base) {
    unsigned int lhs = 1;
    unsigned int rhs = 1;
    for (size_t i = 0; i < number; ++i) {
        rhs += lhs;
        lhs = rhs - lhs;
        rhs %= base;
        lhs %= base;
    }

    return lhs;
}


int main() {

    unsigned int trainee, k;

    std::cin >> trainee >> k;

    std::cout << fibonacci(trainee, static_cast<unsigned int>(pow(10, k)));

    return 0;
}
