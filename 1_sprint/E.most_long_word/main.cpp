#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {

    size_t length;
    std::string most_long_word, current_word;

    std::cin >> length;
    std::cin.ignore(1);

    std::string sentence;
    std::getline(std::cin, sentence);

    std::istringstream iss(sentence);

    while (iss >> current_word) {
        if (current_word.size() > most_long_word.size()) {
            most_long_word = std::move(current_word);
        }
    }

    std::cout << most_long_word << "\n" << most_long_word.size();

    return 0;
}
