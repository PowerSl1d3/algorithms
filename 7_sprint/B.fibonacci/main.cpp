#include <iostream>
#include <vector>
#include <cstdint>

int main() {

   size_t number;

   std::cin >> number;

   std::vector<uint64_t> fibonacci(number + 1);

   fibonacci[0] = 1;
   fibonacci[1] = 1;

   for (size_t i = 2; i < fibonacci.size(); ++i) {

      fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
      fibonacci[i] %= 1'000'000'007u;

   }

   std::cout << fibonacci.back();

   return 0;
}
