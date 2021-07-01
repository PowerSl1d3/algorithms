#include <iostream>
#include <string>
#include <vector>

/*
 * ID удачной посылки: 52043496
 * Временная сложность: O(n*m), где n и m - размеры входных строк
 * Пространственная сложность: O(n*m)
 * Описание алгоритма: Алгоритм итеративно заполняет таблицу dp, строя расстояние Левенштейна для
 * префиксов строк. Доказательство корректности алгоритма: https://ru.wikipedia.org/wiki/Расстояние_Левенштейна
 */

int main() {

   std::string first_string, second_string;

   std::cin >> first_string >> second_string;

   std::vector<std::vector<size_t>> dp(first_string.size() + 1, std::vector<size_t>(second_string.size() + 1));
   dp[0][0] = 0;

   for (size_t i = 0; i < dp.size(); ++i) {

      for (size_t j = 0; j < dp[i].size(); ++j) {

         if (i == 0) {

            dp[i][j] = j;

         } else if (j == 0) {

            dp[i][j] = i;

         } else {

            dp[i][j] = std::min(std::min(dp[i - 1][j] + 1,
                                         dp[i][j - 1] + 1),
                                dp[i - 1][j - 1] + static_cast<size_t>(
                                         first_string[i - 1] != second_string[j - 1]));

         }

      }

   }

   std::cout << dp.back().back();

   return 0;
}
