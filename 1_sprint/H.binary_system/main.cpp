#include <iostream>
#include <string>

int main() {

    std::string first_number, second_number, answer("");

    std::cin >> first_number >> second_number;

    uint8_t tmp = 0;
    for (int i = first_number.size() - 1, j = second_number.size() - 1;
         i >= 0 || j >= 0 || tmp == 1;
         i--, j--) {
        tmp += (i >= 0) ? first_number[i] - '0' : 0;
        tmp += (j >= 0) ? second_number[j] - '0' : 0;
        answer = static_cast<char>(tmp % 2 + '0') + answer;
        tmp /= 2;
    }

    std::cout << answer;

    return 0;
}
