#include <iostream>
#include <vector>

int main() {

   size_t number_of_days;

   std::cin >> number_of_days;

   std::vector<int> days(number_of_days);

   for (int& day : days) {

      std::cin >> day;

   }

   size_t best_score = 0;

   for (size_t i = 0; i < days.size() - 1; ++i) {

      if (days[i] < days[i + 1]) {

         size_t j = i + 1;
         while (j < days.size() - 1 && days[j] < days[j + 1]) {

            ++j;

         }
         best_score += days[j] - days[i];
         i = j;

      }

   }

   std::cout << best_score;
   std::cout.flush();

   return 0;
}
