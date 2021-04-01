#include <iostream>
#include <vector>

int get_hash_from_range(const std::vector<int>& range, const int start, const int end) {

   int sum = 0;

   for (size_t i = start; i < end; ++i) {

      sum += range[i];

   }

   return sum;

}

int main() {

   size_t first_team_size, second_team_size;

   std::cin >> first_team_size;

   std::vector<int> first_team_points(first_team_size);

   for (int& points : first_team_points) {

      std::cin >> points;

   }

   std::cin >> second_team_size;

   std::vector<int> second_team_points(second_team_size);

   for (int& points : second_team_points) {

      std::cin >> points;

   }

   for (size_t i = 0; i < )

   return 0;
}
