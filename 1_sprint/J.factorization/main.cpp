#include <iostream>

int main() {

    uint32_t number;

    std::cin >> number;

    for (uint64_t prob = 2; prob * prob <= number; prob++) {
        while (number % prob == 0) {
            std::cout << prob << ' ';
            number /= prob;
        }
    }

    if (number != 1) {
        std::cout << number;
    }

    return 0;
}
