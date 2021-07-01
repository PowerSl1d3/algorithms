#include <iostream>
#include <vector>
#include <cstdint>

int main() {

   int64_t number_of_steps, k;

   std::cin >> number_of_steps >> k;

   std::vector<int64_t> stair(number_of_steps, 0);

   stair[0] = 1;
   for (int64_t i = 1; i < stair.size(); ++i) {

      for (int64_t j = std::max(static_cast<int64_t>(0), i - k); j < i; ++j) {

         stair[i] += stair[j] % 1'000'000'007;

      }

      stair[i] %= 1'000'000'007;

   }

   std::cout << stair.back();
   std::cout.flush();

   return 0;
}
