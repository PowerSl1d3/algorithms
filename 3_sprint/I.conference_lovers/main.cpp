#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {

   size_t number_of_students;

   std::cin >> number_of_students;

   std::vector<std::pair<int, int>> universities(10'001);

   for (size_t i = 0; i < universities.size(); ++i) {
      universities[i].second = i;
   }

   int student;
   for (size_t i = 0;  i < number_of_students; ++i) {
      std::cin >> student;
      --universities[student].first;
   }

   std::sort(universities.begin(), universities.end());

   int top;
   std::cin >> top;

   for (size_t i = 0; i < top; ++i) {
      std::cout << universities[i].second << ' ';
   }

   return 0;
}
