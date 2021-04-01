#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <tuple>

class Stack {
    std::vector<char> stack;
public:
    void push(char number) {
        stack.push_back(number);
    }
    [[nodiscard]] std::pair<bool, char> pop() {

        if (stack.empty()) {
            return std::make_pair(true, 0);
        }

        char symbol = stack.back();
        stack.pop_back();

        return std::make_pair(false, symbol);
    }

    bool empty() const {
        return stack.empty();
    }
};

bool check_bracket_is_correct(const std::string& bracket_sequence) {

    Stack stack;

    char prev_bracket;
    bool error = true;

    for (auto bracket : bracket_sequence) {

        if (bracket == '(' || bracket == '{' || bracket == '[') {
            stack.push(static_cast<char>(bracket));
        } else {
            std::tie(error, prev_bracket) = stack.pop();
            if (error) {
                return false;
            }

            if (prev_bracket == bracket) {
                return false;
            };
        }

    }

    return stack.empty();

}

void bracket_generator(int count, int current_count_of_brackets, std::string prev_bracket_sequence) {

    if (current_count_of_brackets == count) {

        if (check_bracket_is_correct(prev_bracket_sequence)) {
            std::cout << prev_bracket_sequence << '\n';
        }

        return;
    }

    bracket_generator(count, current_count_of_brackets + 1, prev_bracket_sequence + "(");
    bracket_generator(count, current_count_of_brackets + 1, prev_bracket_sequence + ")");

}

int main() {

    int count;

    std::cin >> count;

    bracket_generator(2 * count, 0, {});

    return 0;
}
