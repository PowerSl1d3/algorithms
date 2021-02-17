#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <exception>

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

int main() {

    Stack stack;

    int bracket, prev_bracket;
    bool error = true;

    while ((bracket = getchar()) != '\n') {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            stack.push(static_cast<char>(bracket));
        } else {
            std::tie(error, prev_bracket) = stack.pop();
            if (error) {
                std::cout << "False";
                return 0;
            }
            switch (prev_bracket) {
                case '(':
                    if (bracket != ')') {
                        std::cout << "False";
                        return 0;
                    }
                    break;
                case '{':
                    if (bracket != '}') {
                        std::cout << "False";
                        return 0;
                    }
                    break;
                case '[':
                    if (bracket != ']') {
                        std::cout << "False";
                        return 0;
                    }
                    break;
                default:
                        throw std::runtime_error("Error");
            }
        }
    }

    if (!stack.empty()) {
        std::cout << "False";
    } else {
        std::cout << "True";
    }

    return 0;
}

