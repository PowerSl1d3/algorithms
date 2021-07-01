#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void DFS(const std::vector<std::vector<int>>& list_of_adjacency,
         std::vector<int>& visited_vertices,
         int start_vertex,
         int component_color) {

   visited_vertices[start_vertex] = component_color;

   for (const int vertex : list_of_adjacency[start_vertex]) {

      if (visited_vertices[vertex] == -1) {

         DFS(list_of_adjacency, visited_vertices, vertex, component_color);

      }

   }

}

std::vector<int> ComponentConnectivity(const std::vector<std::vector<int>> &list_of_adjacency) {

   std::vector<int> visited_vertices(list_of_adjacency.size(), -1);
   int component_color = 1;

   for (size_t i = 0; i < visited_vertices.size(); ++i) {

      if (visited_vertices[i] == -1) {

         DFS(list_of_adjacency, visited_vertices, static_cast<int>(i), component_color);
         ++component_color;

      }

   }

   return visited_vertices;

}

int main() {

   int number_of_vertices, number_of_edges;

   std::cin >> number_of_vertices >> number_of_edges;

   std::vector<std::pair<int, int>> list_of_edges(number_of_edges);

   for (auto& edge : list_of_edges) {

      std::cin >> edge.first >> edge.second;

   }

   std::sort(list_of_edges.begin(), list_of_edges.end());

   std::vector<std::vector<int>> list_of_adjacency(number_of_vertices);

   for(const auto& edge : list_of_edges) {

      list_of_adjacency[edge.first - 1].push_back(edge.second - 1);
      list_of_adjacency[edge.second - 1].push_back(edge.first - 1);

   }

   list_of_edges.clear();

   auto answer = ComponentConnectivity(list_of_adjacency);

   std::map<int, std::vector<int>> component_connectivity;

   for (size_t i = 0; i < answer.size(); ++i) {

      component_connectivity[answer[i]].push_back(i+1);

   }

   for (auto& [component, vertices] : component_connectivity) {

      std::sort(vertices.begin(), vertices.end());

   }

   std::cout << component_connectivity.size() << '\n';

   for (const auto& [component, vertices] : component_connectivity) {

      for (const int vertex : vertices) {

         std::cout << vertex << ' ';

      }

      std::cout << '\n';

   }

   std::cout.flush();

   return 0;
}
