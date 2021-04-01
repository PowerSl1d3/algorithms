#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

   int count;

   std::cin >> count;

   std::vector<std::string> numbers(count);

   for (auto& number : numbers) {
      std::cin >> number;
   }

   std::sort(numbers.begin(), numbers.end(),
             [](const std::string& lhs, const std::string& rhs) {
                 if (lhs + rhs > rhs + lhs) {
                    return true;
                 }

                 return false;
   }
   );

   for (const auto& number : numbers) {
      std::cout << number;
   }

   return 0;
}
