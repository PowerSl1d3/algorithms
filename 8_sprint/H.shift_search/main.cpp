#include <iostream>
#include <vector>

int find(const std::vector<int>& measurements,
         const std::vector<int>& pattern,
         size_t start = 0) {

    if (measurements.size() < pattern.size()) {

        return -1;

    }

    for (size_t i = start; i < measurements.size() - pattern.size() + 1; ++i) {

        bool match = true;

        int pattern_diff = measurements[i] - pattern[0];

        for (size_t offset = 1; offset < pattern.size(); ++offset) {

            int current_diff = measurements[i + offset] - pattern[offset];

            if (pattern_diff != current_diff) {

                match = false;
                break;

            }

        }

        if (match) {

            return static_cast<int>(i);

        }

    }

    return -1;

}

std::vector<int> find_all(const std::vector<int>& measurements,
                          const std::vector<int>& pattern) {

    int last_occurrence = 0;
    std::vector<int> all_occurrences;

    while ((last_occurrence = find(measurements, pattern, last_occurrence)) != -1) {

        all_occurrences.push_back(last_occurrence);
        ++last_occurrence;

    }

    return all_occurrences;

}

int main() {

    size_t number_of_days;

    std::cin >> number_of_days;

    std::vector<int> measurements(number_of_days);

    for (int& day : measurements) {

        std::cin >> day;

    }

    size_t number_of_elements_in_pattern;

    std::cin >> number_of_elements_in_pattern;

    std::vector<int> pattern(number_of_elements_in_pattern);

    for (int& element : pattern) {

        std::cin >> element;

    }

    for (int occurrence : find_all(measurements, pattern)) {

        std::cout << ++occurrence << ' ';

    }

    return 0;
}
