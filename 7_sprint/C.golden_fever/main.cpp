#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdint>

int main() {

   int64_t number_of_heaps, carrying_capacity;

   std::cin >> carrying_capacity >> number_of_heaps;

   std::vector<std::pair<int64_t, int64_t>> heaps(number_of_heaps);

   for (auto& heap : heaps) {

      std::cin >> heap.first >> heap.second;

   }

   std::sort(heaps.rbegin(), heaps.rend());

   uint64_t max_sum = 0;

   for (const auto& heap : heaps) {

      if (heap.second > carrying_capacity) {

         max_sum += heap.first * carrying_capacity;
         carrying_capacity = 0;
         break;

      } else {

         carrying_capacity -= heap.second;
         max_sum += heap.first * heap.second;

      }

   }

   std::cout << max_sum;
   std::cout.flush();

   return 0;
}
