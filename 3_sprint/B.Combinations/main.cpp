#include <iostream>
#include <vector>
#include <string>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {

    for (const T& element : vec) {
        os << element;
    }

    return os;
}

void get_combinations(std::string numbers, std::string prefix, const std::vector<std::vector<char>>& telephone_numbers) {

    if (!numbers.empty()) {
        for (char letter : telephone_numbers[*numbers.begin() - '2']) {
            get_combinations({numbers.begin() + 1, numbers.end()}, prefix + letter, telephone_numbers);
        }
    } else {
        std::cout << prefix << ' ';
    }

}

int main() {

    std::vector<std::vector<char>> telephone_numbers =
            {{'a', 'b', 'c'},
             {'d', 'e', 'f'},
             {'g', 'h', 'i'},
             {'j', 'k', 'l'},
             {'m', 'n', 'o'},
             {'p', 'q', 'r', 's'},
             {'t', 'u', 'v'},
             {'w', 'x', 'y', 'z'}
            };

    std::string numbers;

    std::cin >> numbers;

    get_combinations(numbers, {}, telephone_numbers);

    return 0;
}
