#include <iostream>

unsigned int fibonacci(unsigned int number) {
    if (number == 0 || number == 1) {
        return 1;
    }

    return fibonacci(number - 1) + fibonacci(number - 2);
}


int main() {

    unsigned int trainee;

    std::cin >> trainee;

    std::cout << fibonacci(trainee);

    return 0;
}
