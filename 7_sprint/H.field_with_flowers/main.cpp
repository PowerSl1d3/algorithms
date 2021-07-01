#include <iostream>
#include <vector>
#include <limits>

int main() {

   size_t rows;
   size_t cols;

   std::cin >> rows >> cols;

   std::vector<std::vector<bool>> field(rows, std::vector<bool>(cols));
   std::string current_line;

   for (size_t i = field.size() - 1; i != std::numeric_limits<size_t>::max(); --i) {

      std::cin >> current_line;

      for (size_t j = 0; j < field[i].size(); ++j) {

         field[i][j] = current_line[j] - '0';

      }

   }

   std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1, 0));

   dp[1][1] = field[0][0];

   for (size_t i = 1; i < dp.size(); ++i) {

      for (size_t j = 1; j < dp[i].size(); ++j) {

         dp[i][j] = field[i - 1][j - 1] + std::max(dp[i - 1][j], dp[i][j - 1]);

      }

   }

   std::cout << dp.back().back();
   std::cout.flush();

   return 0;
}
