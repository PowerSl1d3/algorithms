#include <iostream>
#include <string>
#include <stack>

int main() {

   std::string line;

   std::getline(std::cin, line);

   std::stack<std::string> reversed_text;

   auto start_of_current_word = line.begin();
   for (auto it = line.begin(); it != line.end(); ++it) {

      if (*it == ' ') {

         reversed_text.push({start_of_current_word, it});
         start_of_current_word = it + 1;

      }

   }

   reversed_text.push({start_of_current_word, line.end()});

   while (!reversed_text.empty()) {

      std::cout << reversed_text.top() << ' ';
      reversed_text.pop();

   }

   return 0;
}
