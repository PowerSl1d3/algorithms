#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <cstdint>

int main() {

    uint32_t number_of_lines;
    std::string input_line;
    std::unordered_set<std::string> sections;
    std::vector<std::string> sections_by_input_order;

    std::cin >> number_of_lines;
    std::cin.ignore(1);

    sections_by_input_order.reserve(number_of_lines);

    for (size_t i = 0; i < number_of_lines; i++) {

        std::getline(std::cin, input_line);

        if (sections.count(input_line) == 1) {
            continue;
        }

        sections.insert(input_line);

        sections_by_input_order.push_back(input_line);

    }

    for (const auto& string : sections_by_input_order) {

        std::cout << string << "\n";

    }

    return 0;
}
