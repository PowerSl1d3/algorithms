#include <iostream>
#include <string>
#include <string.h>

int main() {

   std::string first_line, second_line;

   std::cin >> first_line >> second_line;

   std::string normal_first_line, normal_second_line;

   for (char character : first_line) {

      if (static_cast<int>(character) % 2 == 0) {

         normal_first_line.push_back(character);

      }

   }

   for (char character : second_line) {

      if (static_cast<int>(character) % 2 == 0) {

         normal_second_line.push_back(character);

      }

   }

   int string_compare = strcmp(normal_first_line.c_str(), normal_second_line.c_str());

   if (string_compare < 0) {

      std::cout << -1;
      return 0;

   } else if (string_compare == 0) {

      std::cout << 0;
      return 0;

   }

   std::cout << 1;

   return 0;
}
