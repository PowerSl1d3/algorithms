#include <iostream>
#include <string>
#include <unordered_map>

int main() {

   std::string first_word, second_word;
   std::unordered_map<char, char> first_string_to_second, second_string_to_first;

   std::cin >> first_word >> second_word;

   if (first_word.size() != second_word.size()) {

      std::cout << "NO";
      return 0;

   }

   for (size_t i = 0; i < first_word.size(); ++i) {

      if ((first_string_to_second.count(first_word[i]) != 0 &&
           first_string_to_second[first_word[i]] != second_word[i]) ||
          (second_string_to_first.count(second_word[i]) != 0 &&
           second_string_to_first[second_word[i]] != first_word[i])) {
         std::cout << "NO";
         return 0;
      } else {
         first_string_to_second[first_word[i]] = second_word[i];
         second_string_to_first[second_word[i]] = first_word[i];
      }

   }

   std::cout << "YES";

   return 0;
}
