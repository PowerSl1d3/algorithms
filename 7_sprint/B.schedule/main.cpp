#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int main() {

   size_t number_of_lessons;

   std::cin >> number_of_lessons;

   std::vector<std::pair<float, float>> schedule(number_of_lessons);

   for (auto& lesson : schedule) {

      std::cin >> lesson.first >> lesson.second;

   }

   std::sort(schedule.begin(), schedule.end(), [](const std::pair<float, float>& lhs, const std::pair<float, float>& rhs)
   {

      return std::tie(lhs.second, lhs.first) < std::tie(rhs.second, rhs.first);

   });

   std::vector<std::pair<float, float>> answer;
   answer.push_back(*schedule.begin());

   for (size_t i = 1; i < schedule.size(); ++i) {

      if (schedule[i].first >= answer.back().second) {

         answer.push_back(schedule[i]);

      }

   }

   std::cout << answer.size() << '\n';

   for (const auto& lesson : answer) {

      std::cout << lesson.first << ' ' << lesson.second << '\n';

   }

   std::cout.flush();

   return 0;
}
