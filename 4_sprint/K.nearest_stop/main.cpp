#include <iostream>
#include <utility>
#include <vector>

int pow(const int base, const int exponent) {

   int copy_base = base;

   if (exponent == 0) {

      return 1;

   }

   for (int i = 1; i < exponent; ++i) {

      copy_base *= base;

   }

   return copy_base;

}

int abs(int x) {

   return (x < 0) ? -x : x;

}

std::vector<std::vector<bool>> generate_points_around_position(const std::pair<int, int>& position) {

   std::vector<std::vector<bool>> result;
   result.assign(21, std::vector<bool>(21, false));

   for (int i = position.first; i <= position.first + 20; ++i) {

      for (int j = position.second + 20; j >= position.second; --j) {

         if (pow(i - position.first, 2) + pow(j - position.second, 2) <= 400) {

            result[i][j] = true;

         }

      }

   }

   return result;

}

int main() {

   auto vec = generate_points_around_position({0,0});

   for (size_t i = 0; i < vec.size(); ++i) {

      for (size_t j = 0; j < vec[i].size(); ++j) {

         std::cout << vec[i][j] << ' ';

      }

      std::cout << std::endl;

   }

   size_t number_of_stations, number_of_bus_stop;

   std::cin >> number_of_stations;

   std::vector<std::pair<int, int>> stations(number_of_stations);

   for (auto& station : stations) {

      std::cin >> station.first >> station.second;

   }

   std::cin >> number_of_bus_stop;

   std::vector<std::pair<int, int>> bus_stops(number_of_bus_stop);

   for (auto& bus_stop : bus_stops) {

      std::cin >> bus_stop.first >> bus_stop.second;

   }

   std::vector<std::pair<int, int>> station_to_bus_stop;

   for (size_t i = 0; i < stations.size(); ++i) {

      for (size_t j = 0; j < bus_stops.size(); ++j) {

         if (pow(bus_stops[j].first - stations[i].first, 2) + pow(bus_stops[j].second - stations[i].second, 2) <= 400) {



         }

      }

   }
   return 0;
}

