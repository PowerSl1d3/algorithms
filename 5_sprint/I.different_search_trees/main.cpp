#include <iostream>

int get_different_BTrees_count(size_t number_of_elements) {

   if (number_of_elements == 0 || number_of_elements == 1) {

      return 1;

   }

   int answer = 0;

   for (size_t i = 0; i < number_of_elements; ++i) {

      answer += get_different_BTrees_count(i) * get_different_BTrees_count(number_of_elements - i - 1);

   }

   return answer;

}

int main() {

   size_t number_of_elements;

   std::cin >> number_of_elements;

   std::cout << get_different_BTrees_count(number_of_elements);

   return 0;
}
