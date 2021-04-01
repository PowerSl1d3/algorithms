#include <iostream>
#include <vector>
#include <algorithm>

int main() {

   int count_of_house, total_sum;

   std::cin >> count_of_house >> total_sum;

   std::vector<int> houses(count_of_house);

   for (int& house : houses) {
      std::cin >> house;
   }

   std::sort(houses.begin(), houses.end());

   int number_of_houses_to_buy = 0;
   int index = 0;
   while (total_sum >= 0 && index < count_of_house) {

      total_sum -= houses[index++];
      if (total_sum >= 0) {
         ++number_of_houses_to_buy;
      }

   }

   std::cout << number_of_houses_to_buy;

   return 0;
}

