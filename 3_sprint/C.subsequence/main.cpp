#include <iostream>
#include <string>

int main() {

   std::string sequence, subsequence;

   std::getline(std::cin, subsequence);
   std::getline(std::cin, sequence);

   size_t index = 0;
   if (subsequence.empty()) {
      std::cout << "True";
      return 0;
   }

   for (char letter : sequence) {
      if (letter == subsequence[index]) {
         ++index;
      }
   }

   if (index == subsequence.size()) {
      std::cout << "True";
   } else {
      std::cout << "False";
   }

   return 0;
}
