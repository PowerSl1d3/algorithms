#include <iostream>
#include <vector>
#include "merge_sort.h"

int main() {

   std::vector<int> array{4, 5, 3, 0, 1, 2};

   merge_sort(array.begin(), array.begin() + 4);

   for (const int element : array) {
      std::cout << element << ' ';
   }

   return 0;
}
