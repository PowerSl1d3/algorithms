#include <iostream>
#include <vector>
#include <algorithm>

enum class color {
    WHITE = 0,
    GRAY = 1,
    BLACK = 2
};

void DFS(const std::vector<std::vector<int>>& list_of_adjacency,
         std::vector<color>& visited_vertices,
         std::vector<int>& entry_time,
         std::vector<int>& leave_time,
         int& time,
         int start_vertex = 0) {

   entry_time[start_vertex] = time;
   ++time;
   visited_vertices[start_vertex] = color::GRAY;

   for (const int vertex : list_of_adjacency[start_vertex]) {

      if (visited_vertices[vertex] == color::WHITE) {

         DFS(list_of_adjacency, visited_vertices, entry_time, leave_time, time, vertex);

      }

   }

   leave_time[start_vertex] = time;
   ++time;
   visited_vertices[start_vertex] = color::BLACK;

}

int main() {

   int number_of_vertices, number_of_edges;

   std::cin >> number_of_vertices >> number_of_edges;

   std::vector<std::pair<int, int>> list_of_edges(number_of_edges);

   for (auto& edge : list_of_edges) {

      std::cin >> edge.first >> edge.second;

   }

   std::vector<std::vector<int>> list_of_adjacency(number_of_vertices);

   for(const auto& edge : list_of_edges) {

      list_of_adjacency[edge.first - 1].emplace_back(edge.second - 1);

   }

   list_of_edges.clear();

   for(auto& vertex_adjacency : list_of_adjacency) {

      std::sort(vertex_adjacency.begin(), vertex_adjacency.end());

   }

   std::vector<color> visited_vertices(number_of_vertices, color::WHITE);
   std::vector<int> entry_time(number_of_vertices);
   std::vector<int> leave_time(number_of_vertices);
   int time = 0;

   DFS(list_of_adjacency, visited_vertices, entry_time, leave_time, time);

   for (size_t i = 0; i < number_of_vertices; ++i) {

      std::cout << entry_time[i] << ' ' << leave_time[i] << '\n';

   }

   std::cout.flush();

   return 0;
}
