#include <iostream>
#include <vector>
#include <cstdint>

int main() {

   size_t number_of_ingots;
   uint64_t max_weight;

   std::cin >> number_of_ingots >> max_weight;

   std::vector<uint64_t> weights_of_ingots(number_of_ingots);

   for (uint64_t& weight : weights_of_ingots) {

      std::cin >> weight;

   }

   std::vector<uint64_t> base(max_weight + 1, 0);
   std::vector<uint64_t> current_line_computing(max_weight + 1, 0);
   std::vector<uint64_t> tmp;
   for (size_t i = 0; i < base.size(); ++i) {

      if (weights_of_ingots[0] <= i) {

         base[i] = weights_of_ingots[0];

      }

   }

   for (size_t i = 1; i < number_of_ingots; ++i) {

      for (size_t j = 1; j < current_line_computing.size(); ++j) {

         if (static_cast<int64_t>(j) - static_cast<int64_t>(weights_of_ingots[i]) < 0) {

            if (static_cast<int64_t>(j) - static_cast<int64_t>(weights_of_ingots[i - 1]) >= 0) {

               current_line_computing[j] = base[j];

            }

            continue;

         }

         current_line_computing[j] = std::max(base[j], weights_of_ingots[i] + base[j - weights_of_ingots[i]]);

      }

      tmp = std::move(base);
      base = std::move(current_line_computing);
      current_line_computing = std::move(tmp);

      for (auto& element : current_line_computing) {

         element = 0;

      }

   }

   std::cout << base.back();

   return 0;
}