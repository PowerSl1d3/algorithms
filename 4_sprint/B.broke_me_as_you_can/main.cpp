#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>

uint64_t get_hash_value(const std::string& input_string, const uint64_t base, const uint64_t mod) {

    if (input_string.empty()) {

        return 0u;

    } else if (input_string.size() == 1) {

        return *input_string.begin();

    }

    uint64_t hash = input_string[0] * base + input_string[1];

    for (size_t i = 2; i < input_string.size(); ++i) {

        hash = (hash * base + input_string[i]) % mod;

    }

    return hash % mod;

}

uint32_t factorial(uint32_t x) {

    return (x <= 1) ? (1) : ( x * factorial(x - 1));

}

std::vector<std::string> get_all_permutations(std::string input_string) {

    std::vector<std::string> all_permutations;

    all_permutations.reserve(factorial(input_string.size()));

    do {

        all_permutations.push_back(input_string);

    } while (std::next_permutation(input_string.begin(), input_string.end()));

    return all_permutations;

}

int main() {

    uint64_t base = 1000;

    uint64_t mod = 123'987'123;

    std::string alphabet = "abcdefghijk";

    std::vector<std::string> all_permutation = get_all_permutations(alphabet);

    for (size_t i = 0, end = factorial(alphabet.size()); i < end; ++i ) {

        std::cout << "Now i computing permutations for " << all_permutation[i] << "\n";

        for (size_t j = i + 1; j < end; ++j) {

            if (get_hash_value(all_permutation[i], base, mod) == get_hash_value(all_permutation[j], base, mod)) {
                std::cout << "Hash value of " << all_permutation[i] << "(" << get_hash_value(all_permutation[i], base, mod)
                << ") == " << all_permutation[j] << "(" << get_hash_value(all_permutation[j], base, mod) << ")";
                return 0;
            }

        }

    }



    return 0;
}
