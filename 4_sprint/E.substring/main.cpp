#include <iostream>
#include <string>
#include <vector>

size_t longest_unique_substring(const std::string& string) {

   size_t res = 0;

   std::vector<int> last_index(256, -1);

   size_t i = 0;

   for (size_t j = 0; j < string.size(); ++j) {

      i = std::max(static_cast<int>(i), last_index[string[j]] + 1);

      res = std::max(res, j - i + 1);

      last_index[string[j]] = j;

   }

   return res;

}

int main() {

   std::string input_string;

   std::cin >> input_string;

   std::cout << longest_unique_substring(input_string);

   return 0;
}
