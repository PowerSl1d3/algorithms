#include <iostream>
#include <string>
#include <cstdint>

int main() {

    std::string input_string;

    uint64_t base, mod;

    std::cin >> base >> mod >> input_string;

    if (input_string.size() == 0) {

        std::cout << 0u;
        return 0;

    } else if (input_string.size() == 1) {

        std::cout << static_cast<uint32_t>(*input_string.begin());
        return 0;

    }

    uint64_t hash = input_string[0] * base + input_string[1];

    for (size_t i = 2; i < input_string.size(); ++i) {

        hash = (hash * base + input_string[i]) % mod;

    }

    std::cout << hash % mod;

    return 0;
}
