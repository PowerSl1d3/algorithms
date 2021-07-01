#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

   std::string base_line;

   std::cin >> base_line;

   size_t number_of_other_lines;

   std::cin >> number_of_other_lines;

   std::vector<std::pair<size_t, std::string>> other_lines(number_of_other_lines);

   for (auto& line_and_index : other_lines) {

      std::cin >> line_and_index.second >> line_and_index.first;

   }

   std::sort(other_lines.begin(), other_lines.end());

   size_t next_index_to_insert_line = other_lines.begin()->first;
   size_t index_of_current_inserting_row = 0;

   for (size_t i = 0; i < base_line.size() + 1; ++i) {

      if (i == next_index_to_insert_line) {

         std::cout << other_lines[index_of_current_inserting_row].second;

         ++index_of_current_inserting_row;
         next_index_to_insert_line = other_lines[index_of_current_inserting_row].first;

      }

      if (i == base_line.size()) {

         continue;

      }
      std::cout << base_line[i];

   }


   return 0;

}
