#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {

    for (const T& element : v) {

        std::cout << element << '\n';

    }

    return os;

}

int main() {

    size_t number_of_words;

    std::cin >> number_of_words;

    std::unordered_map<std::string, std::vector<std::string>> from_camel_case_to_words;

    std::string current_word;

    for (size_t i = 0; i < number_of_words; ++i) {

        std::string current_words_camel_case;
        std::cin >> current_word;

        for (const char character : current_word ) {

            if (character >= 'A' && character <= 'Z') {

                current_words_camel_case.push_back(character);

            }

        }

        from_camel_case_to_words[current_words_camel_case].push_back(std::move(current_word));

    }

    return 0;
}
