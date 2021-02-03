#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    size_t n;

    std::cin >> n;

    std::vector<int> weather(n);

    for (int& i : weather) {
        std::cin >> i;
    }

    if (n == 1) {
        std::cout << 1;
        return 0;
    }

    size_t count = 0;

    for(auto start = std::next(weather.begin()), end = std::prev(weather.end()); start != end; start++) {
        if(*start > *std::prev(start) && *start > *std::next(start)) {
            count++;
        }
    }

    if (weather.size() >= 2) {
        if (weather[0] > weather[1]) {
            count++;
        }

        if (weather[weather.size() - 1] > weather[weather.size() - 2]) {
            count++;
        }
    }

    std::cout << count;

    return 0;
}
