#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

enum class color {
    WHITE = 0,
    GRAY = 1,
    BLACK = 2
};

void DFS(const std::vector<std::vector<int>>& list_of_adjacency,
         std::vector<color>& visited_vertices,
         std::stack<int>& sorted_vertex,
         int start_vertex) {

   visited_vertices[start_vertex] = color::GRAY;

   for (const int vertex : list_of_adjacency[start_vertex]) {

      if (visited_vertices[vertex] == color::WHITE) {

         DFS(list_of_adjacency, visited_vertices, sorted_vertex, vertex);

      }

   }

   visited_vertices[start_vertex] = color::BLACK;
   sorted_vertex.push(++start_vertex);

}

std::stack<int> Topological_sort(const std::vector<std::vector<int>>& list_of_adjacency, int start_vertex = 0) {

   std::vector<color> visited_vertices(list_of_adjacency.size(), color::WHITE);
   std::stack<int> sorted_vertex;

   DFS(list_of_adjacency, visited_vertices, sorted_vertex, start_vertex);

   for (size_t i = 0; i < visited_vertices.size(); ++i) {

      if (visited_vertices[i] == color::WHITE) {

         DFS(list_of_adjacency, visited_vertices, sorted_vertex, static_cast<int>(i));

      }

   }

   return sorted_vertex;

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

      list_of_adjacency[edge.first - 1].emplace_back(edge.second - 1);

   }

   std::stack answer = Topological_sort(list_of_adjacency);

   while(!answer.empty()) {

      std::cout << answer.top() << ' ';
      answer.pop();

   }

   std::cout.flush();

   return 0;
}
