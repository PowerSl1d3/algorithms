#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <cstdint>

template <typename T>
struct Hasher {

    std::hash<T> hasher = std::hash<T>();

    size_t operator()(const std::vector<T>& vec) const {

       size_t sum = 0;

       for (const auto& element : vec) {

          sum += hasher(element);

       }

       return sum;

    }

};

struct PairHasher {

    std::hash<int64_t> hasher = std::hash<int64_t>();

    size_t operator()(const std::pair<int64_t, int64_t>& pair) const {

       return hasher(pair.first) + hasher(pair.second);

    }

};

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& pair) {

   os << "[" << pair.first << ", " << pair.second << "]";

   return os;

}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& array) {

   for (const auto& element : array) {

      os << element << ' ';

   }

   return os;

}

int main() {

   std::map<int64_t , std::unordered_set<std::pair<int64_t, int64_t>, PairHasher>> from_sum_to_elements;
   std::unordered_map<int64_t, uint64_t> from_element_to_count;
   uint64_t number_of_elements;
   int64_t destination_sum;

   std::cin >> number_of_elements >> destination_sum;

   std::vector<int64_t> array(number_of_elements);
   std::unordered_set<std::vector<int64_t>, Hasher<int64_t>> unique_fours;

   if (array.empty()) {

      std::cout << 0;
      return 0;

   }

   for (int64_t& element : array) {

      std::cin >> element;
      ++from_element_to_count[element];

   }

   std::sort(array.begin(), array.end());

   for (uint64_t i = 0; i < array.size() - 1; ++i) {

      for (uint64_t j = i + 1; j < array.size(); ++j) {

         from_sum_to_elements[array[i] + array[j]].insert({array[i], array[j]});

      }

   }

   for (const auto& [sum, set] : from_sum_to_elements) {

      if (from_sum_to_elements.count(destination_sum - sum)) {

         for (const auto& first_pair : set) {

            for (const auto& second_pair : from_sum_to_elements[destination_sum - sum]) {

               std::unordered_map<int64_t, uint64_t> current_element_to_count;

               std::vector<int64_t> current_fours = { first_pair.first, first_pair.second, second_pair.first, second_pair.second };
               std::sort(current_fours.begin(), current_fours.end());

               for (const auto& element : current_fours) {

                  ++current_element_to_count[element];

               }

               for (const auto& [element, count] : current_element_to_count) {

                  if (count > from_element_to_count[element]) {

                     current_fours.clear();
                     break;

                  }

               }

               unique_fours.insert(std::move(current_fours));

            }

         }

      }

   }

   std::vector<std::vector<int64_t>> vec_fours;
   vec_fours.reserve(unique_fours.size());

   for (auto& fours : unique_fours) {

      if (fours.empty()) {

         continue;

      }
      vec_fours.push_back(fours);

   }

   std::sort(vec_fours.begin(), vec_fours.end());

   std::cout << vec_fours.size() << "\n";

   for (const auto& four : vec_fours) {

      std::cout << four << "\n";

   }

   return 0;
}