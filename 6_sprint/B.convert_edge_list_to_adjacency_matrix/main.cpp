#include <iostream>
#include <vector>
#include <utility>

int main() {

   int number_of_vertices, number_of_edges;

   std::cin >> number_of_vertices >> number_of_edges;

   std::vector<std::pair<int, int>> list_of_edges(number_of_edges);

   for (auto& edge : list_of_edges) {

      std::cin >> edge.first >> edge.second;

   }

   std::vector<std::vector<bool>> matrix_of_adjacency(number_of_vertices,
                                                      std::vector<bool>(number_of_vertices, false));

   for (const auto& edge : list_of_edges) {

      matrix_of_adjacency[edge.first - 1][edge.second - 1] = true;

   }

   for (const auto& adjacency_of_vertices : matrix_of_adjacency) {

      for (const bool indicator : adjacency_of_vertices) {

         std::cout << indicator << ' ';

      }

      std::cout << '\n';

   }

   return 0;
}
