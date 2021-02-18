#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <tuple>
#include <cmath>
#include <exception>

//ID успешной посылки: 48523023

namespace Math {
    class Calculator {
    private:
        const std::string function_;
        std::stack<int> stack_;

        std::pair<int, int> get_operands_from_stack();
        int evaluate_operands(const int lhs, const int rhs, const char operand) const;

    public:

        Calculator(std::string function);

        int evaluate();
    };

    Calculator::Calculator(std::string function)
    :function_(function)
    {}

    std::pair<int, int> Calculator::get_operands_from_stack() {

        if (stack_.size() < 2u) {
            throw std::invalid_argument("Insufficient number of elements on the stack");
        }

        int rhs = stack_.top();
        stack_.pop();
        int lhs = stack_.top();
        stack_.pop();

        return {lhs, rhs};

    }

    int Calculator::evaluate_operands(const int lhs, const int rhs, const char operand) const {

        switch (operand) {
            case '+':
                return lhs + rhs;
            case '-':
                return lhs - rhs;
            case '*':
                return lhs * rhs;
            case '/':
                if (rhs == 0) {
                    throw std::invalid_argument("Dividing by zero");
                }
                if (lhs < 0 ^ rhs < 0) {
                    return std::floor(static_cast<double>(lhs) / rhs);
                }
                return lhs / rhs;
            default:
                throw std::invalid_argument("Unknown operand: " + std::string(operand, 1));
        }

    }

    int Calculator::evaluate() {

        if (function_.empty()) {
            throw std::runtime_error("Missing function");
        }

        std::istringstream is(function_);
        std::string value;
        int lhs, rhs;

        while (is >> value) {

            if (value.size() == 1 && (value[0] == '+' || value[0] == '-' || value[0] == '*' || value[0] == '/')) {

                std::tie(lhs, rhs) = get_operands_from_stack();
                stack_.push(evaluate_operands(lhs, rhs, value[0]));

            } else {

                stack_.push(std::stoi(value));

            }
        }


        int answer = stack_.top();
        stack_.pop();

        return answer;

    }
}

int main(int argc, char* argv[]) {

    std::string function;

    std::getline(std::cin, function);

    Math::Calculator calculator(std::move(function));

    std::cout << calculator.evaluate() << std::endl;

    return 0;
}
