#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {

   int number_of_islands;

   std::cin >> number_of_islands;

   std::vector<int> islands(number_of_islands);
   std::vector<int> trash_difference(1'000'000, 0);

   for (int & island : islands) {
      std::cin >> island;
   }

   int k_statistic;

   std::cin >> k_statistic;

   for (size_t i = 0; i < islands.size() - 1; ++i) {
      for (size_t j = i + 1; j < islands.size(); ++j) {
         ++trash_difference[std::abs(islands[i] - islands[j])];
      }
   }

   for (size_t i = 0; i < trash_difference.size(); ++i) {
      if (trash_difference[i] == 0) {
         continue;
      }
      k_statistic -= trash_difference[i];
      if (k_statistic <= 0) {
         std::cout << i;
         break;
      }
   }

   return 0;
}

