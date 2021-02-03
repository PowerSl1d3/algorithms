#include <iostream>
#include <string>

int main() {

    std::string sentence;

    std::getline(std::cin, sentence);

    for (int i = 0, j = sentence.size() - 1; i < j; i++, j-- ) {
        while (!isalnum(sentence[i])) {
            i++;
        }
        while (!isalnum(sentence[j])) {
            j--;
        }
        if (tolower(sentence[i]) != tolower(sentence[j])) {
            std::cout << "False";
            return 0;
        }
    }

    std::cout << "True";

    return 0;
}
