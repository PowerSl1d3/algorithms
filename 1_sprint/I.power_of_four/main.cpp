#include <iostream>
#include <cmath>

int main() {

    uint16_t n;

    std::cin >> n;

    uint16_t pow_of_four = 1;

    while (pow_of_four < n) {
        pow_of_four *= 4;
    }

    std::cout << (pow_of_four == n ? "True" : "False");

    return 0;
}
