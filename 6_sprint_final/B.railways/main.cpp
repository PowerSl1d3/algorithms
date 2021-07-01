#include <iostream>
#include <vector>

//ID удачной посылки: 52038344

/*
 * Временная сложность алгоритма: O(V+E).
 * Пространственная сложность алгоритма: O(V * \alpha), где \alpha - константа, обозначающая память, требуемая
 * для стека вызовов DFS.
 * Алгоритм строит железные дороги в столицу, при это дороги, помеченные 'R' строятся направленными вперёд,
 * а дороги, помеченные 'B' строятся назад. Далее, если имеется цикл в таком графе, то это означает, что существует
 * путь от одного города до другого, по двум различным видам дорог.
 */

enum class color {
    WHITE = 0,
    GRAY = 1,
    BLACK = 2
};

void DFS(const std::vector<std::vector<int>>& list_of_adjacency,
         std::vector<color>& visited_vertices,
         int start_vertex = 0) {

   visited_vertices[start_vertex] = color::GRAY;

   for (const int vertex : list_of_adjacency[start_vertex]) {

      if (visited_vertices[vertex] == color::GRAY) {

         throw std::runtime_error("");

      } else if (visited_vertices[vertex] == color::WHITE) {

         DFS(list_of_adjacency, visited_vertices, vertex);

      }

   }

   visited_vertices[start_vertex] = color::BLACK;

}

bool FindCycle(const std::vector<std::vector<int>>& list_of_adjacency) {

   std::vector<color> visited_vertices(list_of_adjacency.size(), color::WHITE);

   for (size_t i = 0; i < list_of_adjacency.size(); ++i) {

      if (visited_vertices[i] == color::WHITE) {

         try {

            DFS(list_of_adjacency, visited_vertices, static_cast<int>(i));

         } catch (std::exception& e) {

            return true;

         }

      }

   }

   return false;

}

int main() {

   size_t number_of_capitals;

   std::cin >> number_of_capitals;

   if (number_of_capitals < 3) {

      std::cout << "YES\n";

      return 0;

   }

   std::vector<std::vector<int>> list_of_adjacency(number_of_capitals);
   std::string current_adjacent_cities;

   for (size_t i = 0; i < number_of_capitals - 1; ++i) {

      std::cin >> current_adjacent_cities;

      for (size_t j = 0; j < current_adjacent_cities.size(); ++j) {

         switch (current_adjacent_cities[j]) {

            case 'R':
               list_of_adjacency[i].emplace_back(j + i + 1);
               break;
            case 'B':
               list_of_adjacency[j + i + 1].emplace_back(i);
               break;

         }

      }

   }

   if (FindCycle(list_of_adjacency)) {

      std::cout << "NO\n";
      return 0;

   }

   std::cout << "YES\n";
   return 0;

}
