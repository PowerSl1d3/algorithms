#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

bool is_cointinue(std::pair<int, int> prev_beds, std::pair<int, int> next_beds) {
   if (next_beds.first >= prev_beds.first && next_beds.first <= prev_beds.second) {
      return true;
   }

   return false;
}

int main() {

   int count;

   std::cin >> count;

   std::vector<std::pair<int, int>> flower_beds(count);
   std::pair<int, int> tmp;

   for (auto& range : flower_beds) {
      std::cin >> range.first >> range.second;
   }

   std::sort(flower_beds.begin(), flower_beds.end());

   std::pair<int, int> prev_flower_beds;

   for (size_t i = 0; i < flower_beds.size(); ++i) {
      prev_flower_beds = flower_beds[i];
      for (size_t j = i + 1; j < flower_beds.size(); ++j) {
         if (is_cointinue(prev_flower_beds, flower_beds[j])) {
            if (prev_flower_beds.second < flower_beds[j].second) {
               prev_flower_beds.second = flower_beds[j].second;
            }
            i = j;
         } else {
            break;
         }
      }
      std::cout << prev_flower_beds.first << ' ' << prev_flower_beds.second << "\n";
   }

   return 0;
}
