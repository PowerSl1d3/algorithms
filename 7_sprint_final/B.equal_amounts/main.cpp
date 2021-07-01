#include <iostream>
#include <vector>
#include <numeric>

/*
 * ID удачной посылки: 52046887
 * Временная сложность: O(sum/2 * n), где sum - сумма элементов входного множества, n - количество элементов
 * в этом множестве
 * Пространственная сложность: O(sum/2 * n)
 * Описание алгоритма: Алгоритм итеративно заполняет таблицу dp, строя множества, из которых мы можем
 * составить i-ю строку(в данном случае i будет суммой элементов, которую можно составить для множества j чисел).
 * Доказательство корректности алгоритма: https://ru.wikipedia.org/wiki/Задача_разбиения_множества_чисел
 */

int main() {

   size_t number_of_elements_in_set;

   std::cin >> number_of_elements_in_set;

   std::vector<int> set(number_of_elements_in_set);

   for(int& element :  set) {

      std::cin >> element;

   }

   int sum = std::accumulate(set.begin(), set.end(), 0);

   if (sum % 2 != 0) {

      std::cout << "False";
      return 0;

   }

   std::vector<std::vector<bool>> dp(sum / 2 + 1, std::vector<bool>(number_of_elements_in_set + 1));

   for (size_t i = 0; i < dp.back().size(); ++i) {

      dp[0][i] = true;

   }

   for (size_t i = 1; i < dp.size(); ++i) {

      dp[i][0] = false;

   }

   for (size_t i = 1; i < dp.size(); ++i) {

      for (size_t j = 1; j < dp[i].size(); ++j) {

         dp[i][j] = dp[i][j - 1];

         if (static_cast<int>(i) >= set[j - 1]) {
            /*
             * Боюсь, что оптимизация с двумя векотрами тут невозиожна или не на столько тривиальна, как
             * мне показалась. Дело в том, что здесь идёт обращение к индексам по i (i - set[j - 1]), которые
             * лежат на предыдущих посчитанных строках, которые мы будем "забывать", храня информацию в двух векторах
             */
            dp[i][j] = dp[i][j] || dp[i - set[j - 1]][j - 1];

         }

      }

   }

   if (dp[sum/2][number_of_elements_in_set]) {

      std::cout << "True";
      return 0;

   }

   std::cout << "False";

   return 0;
}
