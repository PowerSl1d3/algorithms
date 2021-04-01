#include <iostream>
#include <string>
#include <unordered_map>
#include <numeric>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> array) {

   for (const auto& element : array) {

      os << element << ' ';

   }

   return os;

}

int main() {

   std::unordered_map<std::string, std::vector<uint32_t>> sorted_word_to_real_word;
   size_t number_of_words;
   std::string word, sorted_copy_of_word;

   std::cin >> number_of_words;

   for (size_t i = 0; i < number_of_words; ++i) {

      std::cin >> word;

      std::sort(word.begin(), word.end());

      sorted_word_to_real_word[word].push_back(i);

   }

   std::vector<std::vector<std::uint32_t>> copy_of_hash_table;
   copy_of_hash_table.reserve(sorted_word_to_real_word.size());

   for (auto& [key, value] : sorted_word_to_real_word) {

      copy_of_hash_table.push_back(std::move(value));

   }

   std::sort(copy_of_hash_table.begin(), copy_of_hash_table.end());

   for (auto& array : copy_of_hash_table) {

      std::cout << array << "\n";

   }

   return 0;
}
