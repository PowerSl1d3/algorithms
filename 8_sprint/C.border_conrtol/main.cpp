#include <iostream>
#include <string>

int main() {

   std::string first_string, second_string;

   std::cin >> first_string >> second_string;

   if (std::max(first_string.size(), second_string.size()) - std::min(first_string.size(), second_string.size()) > 1) {

      std::cout << "FAIL";
      return 0;

   }

   if (first_string == second_string) {

      std::cout << "OK";
      return 0;

   }

   char tmp;

   for (size_t i = 0, end = std::min(first_string.size(), second_string.size()); i < end; ++i) {

      if (first_string[i] != second_string[i]) {

         tmp = first_string[i];
         first_string[i] = second_string[i];

         if (first_string == second_string) {

            std::cout << "OK";
            return 0;

         }

         second_string[i] = tmp;

         if (first_string == second_string) {

            std::cout << "OK";
            return 0;

         }

         std::swap(first_string[i], second_string[i]);

         std::string_view fs_sw(first_string);
         std::string_view ss_sw(second_string);

         fs_sw.remove_prefix(i + 1);
         ss_sw.remove_prefix(i);

         if (fs_sw == ss_sw) {

            std::cout << "OK";
            return 0;

         }

         fs_sw = std::string_view(first_string);
         ss_sw = std::string_view(second_string);

         fs_sw.remove_prefix(i);
         ss_sw.remove_prefix(i + 1);

         if (fs_sw == ss_sw) {

            std::cout << "OK";
            return 0;

         }

         std::cout << "FAIL";
         return 0;

      }

   }

   std::cout << "OK";

   return 0;

}
