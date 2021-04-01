#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {

   int number_of_segments;

   std::cin >> number_of_segments;

   std::vector<int> segments(number_of_segments);

   for (int& segment : segments) {
      std::cin >> segment;
   }

   std::sort(segments.begin(), segments.end());

   int max_perimeter = 0;

   for (size_t i = segments.size() - 1; i > 1; --i) {
      for (size_t j = i - 1; j > 0; --j) {
         for (size_t k = j - 1; k >= 0 && k != std::numeric_limits<size_t>::max(); --k) {
            if (segments[k] + segments[j] > segments[i] && segments[i] + segments[j] + segments[k] > max_perimeter) {
               std::cout << segments[i] + segments[j] + segments[k] << std::endl;
               return 0;
            }
         }
      }
   }

   return 0;
}
