#include <iostream>
#include <vector>

template <typename Iterator>
std::vector<int> integrate_vector(Iterator begin, Iterator end) {

   std::vector<int> integral(end - begin, 0);
   integral[0] = *begin++;

   for (size_t i = 1; i < integral.size(); ++i) {

      integral[i] = integral[i - 1] + *begin++;

   }

   return integral;

}

int main() {

   //TODO: обработать краевые случаи!

   size_t number_of_rounds;

   std::cin >> number_of_rounds;

   std::vector<int> rounds(number_of_rounds);

   for (int& round : rounds) {

      std::cin >> round;

   }

   for (int& round : rounds) {

      if (round == 0) {
         round = -1;
      }

   }

   for (size_t i = 0; i < rounds.size(); ++i) {

      for (size_t j = rounds.size() - 1; j > i; --j) {

         if (integrate_vector(rounds.begin() + i, rounds.begin() + j + 1).back() == 0) {

            std::cout << j - i + 1;
            return 0;

         }

      }

   }

   std::cout << 1;

   return 0;
}
