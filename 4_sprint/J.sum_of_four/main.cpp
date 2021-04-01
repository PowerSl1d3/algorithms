#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& array) {

   for (const auto& element : array) {

      os << element << ' ';

   }

   return os;

}

int main() {

   size_t number_of_elements;
   int sum;

   std::cin >> number_of_elements >> sum;

   std::vector<int> array(number_of_elements);
   std::vector<std::vector<int>> fours;

   for (int& element : array) {

      std::cin >> element;

   }

   std::sort(array.begin(), array.end());

   for (size_t i = 0;  i < array.size() - 3; ++i) {

      for (size_t j = i + 1; j < array.size() - 2; ++j) {

         for (size_t k = j + 1; k < array.size() - 1; ++k) {

            for (size_t l = k + 1; l < array.size(); ++l) {

               if (array[i] + array[j] + array[k] + array[l] == sum) {

                  if (!fours.empty() && fours.back() == std::vector<int>{array[i], array[j], array[k], array[l]}) {
                     continue;
                  } else {

                     fours.push_back({array[i], array[j], array[k], array[l]});

                  }

               }

            }

         }

      }

   }

   for (auto& four : fours) {

      std::sort(four.begin(), four.end());

   }

   std::sort(fours.begin(), fours.end());

   std::cout << fours.size() << "\n";

   for (const auto& four : fours) {

      std::cout << four << "\n";

   }

   return 0;
}