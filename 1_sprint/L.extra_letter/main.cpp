#include <iostream>
#include <string>
#include <numeric>

uint32_t hash_s(const std::string& sentence) {
    return std::accumulate(sentence.begin(), sentence.end(), 0);
}

int main() {

    std::string first, second;

    std::cin >> first >> second;

    std::cout << static_cast<char>(hash_s(second) - hash_s(first));
    return 0;
}
