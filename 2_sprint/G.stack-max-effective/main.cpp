#include <iostream>
#include <algorithm>
#include <exception>
#include <list>
#include <map>
#include <vector>

class StackMax {
    std::vector<int> stack;
    std::map<int, unsigned> ascending_sequence;
public:
    void push(int number) {
        ++ascending_sequence[number];
        stack.push_back(number);
    }
    [[nodiscard]] bool pop() {
        if (stack.empty()) {
            return false;
        }

        --ascending_sequence[stack.back()];

        if (ascending_sequence[stack.back()] == 0u) {
            ascending_sequence.erase(stack.back());
        }

        stack.pop_back();
        return true;
    }
    [[nodiscard]] int get_max() const {
        if (stack.empty()) {
            throw std::runtime_error("None");
        }
        return std::prev(ascending_sequence.end())->first;
    }
};

int main() {

    int count, push_number;
    StackMax sm;
    std::string command;

    std::cin >> count;

    for (size_t i = 0; i < count; i++) {

        std::cin >> command;

        if (command == "get_max") {
            try {
                std::cout << sm.get_max() << '\n';
            } catch (std::runtime_error& error) {
                std::cout << error.what() << '\n';
            }
        } else if (command == "push") {
            std::cin >> push_number;
            sm.push(push_number);
        } else {
            if (!sm.pop()) {
                std::cout << "error" << '\n';
            }
        }
    }

    return 0;
}

