#include <iostream>

bool all_even(int a, int b, int c) {
    return (a % 2 == 0) && (b % 2 == 0) && (c % 2 == 0);
}

bool all_odd(int a, int b, int c) {
    return (a % 2 == 1) && (b % 2 == 1) && (c % 2 == 1);
}

namespace math {
    void abs(int& a) {

        if (a < 0) {
            a = -a;
        }

    }
}

int main() {

    int a, b, c;

    std::cin >> a >> b >> c; math::abs(a); math::abs(b), math::abs(c);

    std::cout << (all_even(a, b, c) || all_odd(a, b, c) ? ("WIN") : ("FAIL"));

    return 0;
}
