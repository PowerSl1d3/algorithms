#include <iostream>
#include <vector>
#include <unordered_map>

size_t calculate_draw_range(const std::vector<int>& rounds) {

   std::unordered_map<int, size_t> sum_positions;
   int current_sum = 0;
   size_t start_pos = 0;
   size_t end_pos = 0;
   size_t last_zero_pos = 0;

   for (size_t i = 0; i < rounds.size(); ++i) {

      current_sum += rounds[i];

      if (current_sum == 0) {

         last_zero_pos = i + 1;

      }

      if (sum_positions.count(current_sum)) {

         if (i + 1 - sum_positions[current_sum] + 1 > end_pos - start_pos) {

            start_pos = sum_positions[current_sum] + 1;
            end_pos = i + 1;

         }

      } else {

         sum_positions[current_sum] = i;

      }

   }

   return std::max(end_pos - start_pos, last_zero_pos);

}

int main() {

   size_t number_of_rounds;

   std::cin >> number_of_rounds;

   std::vector<int> rounds(number_of_rounds);

   for (int& round : rounds) {

      std::cin >> round;

      if (round == 0) {
         round = -1;
      }


   }

   std::cout << calculate_draw_range(rounds) << std::endl;

   return 0;
}

