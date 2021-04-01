#include <iostream>
#include <map>
#include <vector>

int main() {

   size_t number_of_elements;

   std::cin >> number_of_elements;

   std::map<int, size_t> wardrobe;

   int element;
   for (size_t i = 0; i < number_of_elements; ++i) {
      std::cin >> element;
      ++wardrobe[element];
   }

   for (auto& element : wardrobe) {
      for (size_t i = 0; i < element.second; ++i) {
         std::cout << element.first << ' ';
      }
   }

   return 0;
}
