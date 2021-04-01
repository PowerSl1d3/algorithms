#include <iostream>
#include <vector>
#include <algorithm>

int get_blocks_number(std::vector<int>& array, const std::vector<int>& sorted_array) {

   int number_of_blocks = 0;

   for (size_t i = 0; i < array.size(); ++i) {

      std::sort(array.begin(), array.begin() + i + 1);
      if (std::equal(array.begin(), array.begin() + i + 1, sorted_array.begin(), sorted_array.begin() + i + 1)) {
         ++number_of_blocks;
      }

   }

   return number_of_blocks;

}

int main() {

   int number_of_elements;

   std::cin >> number_of_elements;

   std::vector<int> array(number_of_elements);

   for (int& element : array) {
      std::cin >> element;
   }

   std::vector sorted_copy = array;
   std::sort(sorted_copy.begin(), sorted_copy.end());

   std::cout << get_blocks_number(array, sorted_copy);

   return 0;
}
