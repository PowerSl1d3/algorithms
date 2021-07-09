#include <iostream>
#include <vector>
#include <string>

std::vector<int> prefix_function(const std::string& s) {

    std::vector<int> pi(s.size());
    pi[0] = 0;

    for (size_t i = 1; i < s.size(); ++i) {

        int k = pi[i - 1];

        while (k > 0 && s[k] != s[i]) {

            k = pi[k - 1];

        }

        if (s[k] == s[i]) {

            ++k;

        }

        pi[i] = k;

    }

    return pi;

}

int main() {

    std::string input_line;

    std::cin >> input_line;

    for (const int prefix_value : prefix_function(input_line)) {

        std::cout << prefix_value << ' ';

    }

    return 0;
}
