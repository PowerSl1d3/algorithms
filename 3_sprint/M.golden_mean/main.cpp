#include <iostream>
#include <vector>
#include <algorithm>

int main() {

   int number_of_south_people, number_of_north_people;

   std::cin >> number_of_north_people >> number_of_south_people;

   std::vector<int> north_people(number_of_north_people), south_people(number_of_south_people);

   for (int& people : north_people) {
      std::cin >> people;
   }

   for (int& people : south_people) {
      std::cin >> people;
   }

   std::vector<int> all_people;
   all_people.reserve(number_of_south_people + number_of_north_people);

   std::merge(north_people.begin(), north_people.end(), south_people.begin(), south_people.end(), std::back_inserter(all_people));

   if ((number_of_south_people + number_of_north_people) % 2 == 0) {
      std::cout << (all_people[all_people.size() / 2 - 1] + all_people[all_people.size() / 2]) / 2.0f;
   } else {
      std::cout << all_people[all_people.size() / 2];
   }

   return 0;
}
