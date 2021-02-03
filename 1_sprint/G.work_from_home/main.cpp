#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

std::vector<uint8_t> dec_to_bin(uint16_t number) {

    std::vector<uint8_t> answer;

    while (number >= 2) {
        answer.push_back(number % 2);
        number /= 2;
    }
    answer.push_back(number);

    std::reverse(answer.begin(), answer.end());

    return answer;
}

int main() {

    uint16_t number;

    std::cin >> number;

    for (const uint8_t i : dec_to_bin(number)) {
        printf("%d", i);
    }

    return 0;
}
