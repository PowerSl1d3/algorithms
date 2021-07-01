#include <iostream>
#include <vector>
#include <limits>

int main() {

   size_t number_elements_of_first_sequence;

   std::cin >> number_elements_of_first_sequence;

   std::vector<int> first_sequence(number_elements_of_first_sequence);

   for (int& element : first_sequence) {

      std::cin >> element;

   }

   size_t number_elements_of_second_sequence;

   std::cin >> number_elements_of_second_sequence;

   std::vector<int>second_sequence(number_elements_of_second_sequence);

   for (int& element : second_sequence) {

      std::cin >> element;

   }

   std::vector<std::vector<int>> dp(number_elements_of_first_sequence + 1,
                                    std::vector<int>(number_elements_of_second_sequence + 1, 0));


   for (size_t i = 1; i < dp.size(); ++i) {

      for (size_t j = 1; j < dp[i].size(); ++j) {

         if (first_sequence[i - 1] == second_sequence[j - 1]) {

            dp[i][j] = dp[i - 1][j - 1] + 1;

         } else {

            dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);

         }

      }

   }

   std::cout << dp.back().back() << '\n';

   size_t i = dp.size() - 1;
   size_t j = dp.back().size() - 1;

   std::vector<int> answer_of_first_sequence;
   std::vector<int> answer_of_second_sequence;

   while(i != 0 && j != 0) {

      if (first_sequence[i - 1] == second_sequence[j - 1]) {

         answer_of_first_sequence.push_back(static_cast<int>(i));
         answer_of_second_sequence.push_back(static_cast<int>(j));
         --i;
         --j;

      } else {

         if (dp[i][j] == dp[i - 1][j]) {

            --i;

         } else {

            --j;

         }

      }

   }

   for (size_t i = answer_of_first_sequence.size() - 1; i != std::numeric_limits<size_t>::max(); --i) {

      std::cout << answer_of_first_sequence[i] << ' ';

   }

   std::cout << '\n';

   for (size_t i = answer_of_second_sequence.size() - 1; i != std::numeric_limits<size_t>::max(); --i) {

      std::cout << answer_of_second_sequence[i] << ' ';

   }

   return 0;
}
