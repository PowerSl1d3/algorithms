#include <iostream>
#include <vector>

int main() {

   int number_of_vertices, number_of_edges;

   std::cin >> number_of_vertices >> number_of_edges;

   std::vector<std::pair<int, int>> list_of_edges(number_of_edges);

   for (auto& edge : list_of_edges) {

      std::cin >> edge.first >> edge.second;

   }

   std::vector<std::vector<int>> list_of_adjacency(number_of_vertices);

   for(const auto& edge : list_of_edges) {

      list_of_adjacency[edge.first - 1].emplace_back(edge.second);

   }

   for (const auto& vertices : list_of_adjacency) {

      std::cout << vertices.size() << ' ';

      for (const int& vertex : vertices) {

         std::cout << vertex << ' ';

      }

      std::cout << "\n";

   }

   return 0;
}
