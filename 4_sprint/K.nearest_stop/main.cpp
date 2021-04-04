#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include <algorithm>

namespace new_math {
    int64_t pow(const int64_t base, const int64_t exponent) {

       int64_t copy_base = base;

       if (exponent == 0) {

          return 1;

       }

       for (int64_t i = 1; i < exponent; ++i) {

          copy_base *= base;

       }

       return copy_base;

    }
}

std::pair<int64_t, int64_t> get_sector(const std::pair<int64_t, int64_t>& point) {

   std::pair<int64_t, int64_t> sector;

   if (point.first >= 0) {

      sector.first = point.first / 21;

   } else {

      sector.first = -(-point.first / 21 + 1);

   }

   if (point.second >= 0) {

      sector.second = point.second / 21;

   } else {

      sector.second = -(-point.second / 21 + 1);

   }

   return sector;

}

std::vector<std::pair<int64_t, int64_t>> get_sector_and_sectors_around_sector(const std::pair<int64_t, int64_t>& sector) {


   std::vector<std::pair<int64_t, int64_t>> sectors = {{sector.first, sector.second},
                                              {sector.first, sector.second + 1},
                                              {sector.first + 1, sector.second + 1},
                                              {sector.first + 1, sector.second},
                                              {sector.first + 1, sector.second - 1},
                                              {sector.first, sector.second - 1},
                                              {sector.first - 1, sector.second - 1},
                                              {sector.first - 1, sector.second},
                                              {sector.first - 1, sector.second + 1}};

   return sectors;

}

struct Hasher {

    std::hash<int64_t> hash = std::hash<int64_t>();

    size_t operator()(const std::pair<int64_t, int64_t>& pair) const {

       return hash(pair.first) + hash(pair.second);

    }

};

size_t get_station_with_max_nearest_bus_stops(std::istream& is) {

   std::unordered_map<std::pair<int64_t, int64_t>, std::vector<std::pair<int64_t, int64_t>>, Hasher> station_sectors_to_stations;
   std::unordered_map<std::pair<int64_t, int64_t>, size_t, Hasher> stations_to_index;

   size_t number_of_stations;
   std::pair<int64_t, int64_t> current_station;

   is >> number_of_stations;

   for (size_t i = 0; i < number_of_stations; ++i) {

      is >> current_station.first >> current_station.second;

      station_sectors_to_stations[get_sector(current_station)].push_back(current_station);
      stations_to_index[current_station] = i + 1;

   }

   size_t number_of_bus_stop;
   std::pair<int64_t, int64_t> bus_stop;
   std::unordered_map<std::pair<int64_t, int64_t>, std::vector<std::pair<int64_t, int64_t>>, Hasher> bus_stop_square_to_stops;

   is >> number_of_bus_stop;

   for (size_t i = 0; i < number_of_bus_stop; ++i) {

      is >> bus_stop.first >> bus_stop.second;

      bus_stop_square_to_stops[get_sector(bus_stop)].push_back(bus_stop);


   }

   uint64_t current_max_station_containing_bus_stops = 0u;
   std::vector<uint64_t> index_of_max_bus_stop;

   for (const auto& [stations_sector, stations_in_sector] : station_sectors_to_stations) {

      auto neighborhood_sector_around_station_sector = get_sector_and_sectors_around_sector(stations_sector);

      for (const auto& station : stations_in_sector) {

         uint64_t current_stops_around = 0u;

         for (const auto& neighborhood_sector : neighborhood_sector_around_station_sector) {

            if (bus_stop_square_to_stops.count(neighborhood_sector)) {

               for (const auto& stop_station : bus_stop_square_to_stops[neighborhood_sector]) {

                  if (new_math::pow(stop_station.first - station.first, 2) + new_math::pow(stop_station.second - station.second, 2) <= 400) {

                     ++current_stops_around;

                  }

               }

            }

         }

         if (current_stops_around == current_max_station_containing_bus_stops) {

            index_of_max_bus_stop.push_back(stations_to_index[station]);

         } else if (current_stops_around > current_max_station_containing_bus_stops) {

            current_max_station_containing_bus_stops = current_stops_around;
            index_of_max_bus_stop.clear();
            index_of_max_bus_stop.push_back(stations_to_index[station]);

         }

      }

   }

   std::sort(index_of_max_bus_stop.begin(), index_of_max_bus_stop.end());

   return *index_of_max_bus_stop.begin();

}

int main() {

   std::cout << get_station_with_max_nearest_bus_stops(std::cin);

   return 0;
}

