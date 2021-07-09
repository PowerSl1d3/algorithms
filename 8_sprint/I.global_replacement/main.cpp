#include <iostream>
#include <vector>
#include <string>

std::vector<size_t> find(const std::string& text, const std::string& pattern) {

    std::vector<size_t> result;

    std::string s = pattern + '#' + text;

    std::vector<int> pi(pattern.size());
    pi[0] = 0;

    int prev_pi = 0;

    for (size_t i = 1; i < s.size(); ++i) {

        int k = prev_pi;

        while (k > 0 && s[k] != s[i]) {

            k = pi[k - 1];

        }

        if (s[k] == s[i]) {

            ++k;

        }

        if (i < pattern.size()) {

            pi[i] = k;

        }

        prev_pi = k;

        if (k == pattern.size()) {

            result.push_back(i - 2 * pattern.size());

        }

    }

    return result;

}

int main() {

    std::string text, pattern, filler;

    std::cin >> text >> pattern >> filler;

    std::vector<size_t> entries = find(text, pattern);

    if (entries.empty()) {

        std::cout << text;
        return 0;

    }

    size_t last_entry = entries[0];
    size_t index = 0;

    for (size_t i = 0; i < text.size() + 1; ++i) {

        if (i == last_entry) {

            std::cout << filler;

            if (index < entries.size()) {

                last_entry = entries[++index];

            }

            i += pattern.size() - 1;
            continue;

        }

        if (i == text.size()) {

            break;

        }

        std::cout << text[i];

    }

    return 0;
}
