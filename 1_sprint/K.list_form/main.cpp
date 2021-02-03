#include <iostream>
#include <vector>
#include <cmath>

int main() {

    uint32_t n, first_number = 0, second_number;

    std::cin >> n;

    std::vector<uint32_t> vec(n);

    for (uint32_t & element : vec) {
        std::cin >> element;
    }

    std::cin >> second_number;

    auto it = vec.begin();
    for (uint32_t pow = static_cast<uint32_t>(std::pow(10, n - 1)); pow >= 1; pow /= 10) {
        first_number += *it * pow;
        it++;
    }

    first_number += second_number;
    vec.clear();

    while (first_number > 0) {
        vec.push_back(first_number % 10);
        first_number /= 10;
    }

    for (auto it = vec.rbegin(); it != vec.rend(); it++) {
        std::cout << *it << ' ';
    }

    return 0;
}
