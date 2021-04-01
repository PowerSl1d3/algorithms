#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

uint64_t get_hash(const std::string& input_string, const uint64_t base, const uint64_t mod) {

   if (input_string.empty() == 0) {

      return 0u;

   } else if (input_string.size() == 1) {

      return static_cast<uint32_t>(*input_string.begin());

   }

   uint64_t hash = input_string[0] * base + input_string[1];

   for (size_t i = 2; i < input_string.size(); ++i) {

      hash = (hash * base + input_string[i]) % mod;

   }

   return hash % mod;

}

std::vector<uint64_t> get_powers(const std::string& input_string, const uint64_t base, const uint64_t mod) {

   std::vector<uint64_t> powers(input_string.size() + 1);
   powers[0] = 1u;

   for (size_t i = 1; i < powers.size(); ++i) {
      powers[i] = (powers[i - 1] * base) % mod;
   }

   return powers;

}

std::vector<uint64_t> get_prefixes(const std::string& input_string, const uint64_t base, const uint64_t mod) {

   std::vector<uint64_t> prefix_hashes(input_string.size() + 1);
   prefix_hashes[0] = 0u;

   for (size_t i = 1; i < prefix_hashes.size(); ++i) {
      prefix_hashes[i] = (prefix_hashes[i - 1] * base % mod + input_string[i - 1]) % mod;
   }

   return prefix_hashes;

}

int main() {

   size_t number_of_prefix_hashes, start, end;
   uint64_t base, mod;
   std::string input_string;

   std::cin >> base >> mod >> input_string >> number_of_prefix_hashes;

   const std::vector<uint64_t> powers = get_powers(input_string, base, mod);
   const std::vector<uint64_t> prefixes_hashes = get_prefixes(input_string, base, mod);

   for (size_t i = 0; i < number_of_prefix_hashes; ++i) {

      std::cin >> start >> end;

      std::cout << (prefixes_hashes[end] + mod - (prefixes_hashes[start - 1] * powers[end - (start - 1)]) % mod ) % mod << "\n";

   }

   return 0;
}
