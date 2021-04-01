#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& array) {

   for (const auto& element : array) {

      os << element << ' ';

   }

   return os;

}

std::vector<uint64_t> get_powers(const std::string& input_string, const uint64_t base = 1297u, const uint64_t mod = 4294967296u) {

   std::vector<uint64_t> powers(input_string.size() + 1);
   powers[0] = 1u;

   for (size_t i = 1; i < powers.size(); ++i) {
      powers[i] = (powers[i - 1] * base) % mod;
   }

   return powers;

}

std::vector<uint64_t> get_prefixes(const std::string& input_string, const uint64_t base = 1297u, const uint64_t mod = 4294967296u) {

   std::vector<uint64_t> prefix_hashes(input_string.size() + 1);
   prefix_hashes[0] = 0u;

   for (size_t i = 1; i < prefix_hashes.size(); ++i) {
      prefix_hashes[i] = (prefix_hashes[i - 1] * base % mod + input_string[i - 1]) % mod;
   }

   return prefix_hashes;

}

uint64_t get_hash_value(const std::string& input_array, const size_t start, const size_t end,
                        const std::vector<uint64_t>& powers,
                        const std::vector<uint64_t>& prefixes,
                        const uint64_t base = 1000000007u,
                        const uint64_t mod = 4294967296u) {

   return (prefixes[end] + mod - (prefixes[start - 1] * powers[end - (start - 1)]) % mod ) % mod;


}

int main() {

   std::ifstream ifs("input.txt");

   size_t size_of_substring, min_number_of_occurrences;

   std::unordered_map<uint64_t, std::pair<size_t, size_t>> hash_to_count_and_pos_of_first_coming;

   uint64_t current_substring_hash_value;

   ifs >> size_of_substring >> min_number_of_occurrences;

   std::string input_string;

   ifs >> input_string;

   if (input_string.size() > 10'000'000u) {

      return 0;

   }

   const std::vector<uint64_t> powers = get_powers(input_string);
   const std::vector<uint64_t> prefixes_hashes = get_prefixes(input_string);

   for (size_t i = 0; i + size_of_substring < input_string.size(); ++i) {

      current_substring_hash_value = get_hash_value(input_string, i + 1, i + size_of_substring, powers, prefixes_hashes);

      if (hash_to_count_and_pos_of_first_coming.count(current_substring_hash_value)) {

         ++hash_to_count_and_pos_of_first_coming[current_substring_hash_value].first;

      } else {

         hash_to_count_and_pos_of_first_coming[current_substring_hash_value] = {1, i};

      }

   }

   std::vector<size_t> index_of_first_coming;
   index_of_first_coming.reserve(hash_to_count_and_pos_of_first_coming.size());

   for (const auto& [key, value] : hash_to_count_and_pos_of_first_coming) {

      if (value.first >= min_number_of_occurrences) {

         index_of_first_coming.push_back(value.second);

      }

   }

   std::sort(index_of_first_coming.begin(), index_of_first_coming.end());

   std::cout << index_of_first_coming;

   return 0;
}

