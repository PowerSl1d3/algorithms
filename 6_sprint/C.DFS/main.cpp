#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

enum class color {
    WHITE = 0,
    GRAY = 1,
    BLACK = 2
};

enum class stage {

    first_visit = 0,
    return_visit = 1

};

namespace new_algorithm {

    void DFS(const std::vector<std::vector<int>>& list_of_adjacency,
             std::vector<color>& visited_vertices,
             int start_vertex) {

       std::stack<std::pair<int, stage>> stack;

       stack.push({start_vertex, stage::first_visit});

       while (!stack.empty()) {

          auto [v, stage] = stack.top();
          stack.pop();

          if (visited_vertices[v] == color::WHITE) { //Здесь должно быть stage = stage::first_visit

             stack.push({v, stage::return_visit});
             visited_vertices[v] = color::GRAY;

             std::cout << v + 1 << ' ';

             for (const int& w : list_of_adjacency[v]) {

                if (visited_vertices[w] == color::WHITE) {

                   stack.push({w, stage::first_visit});

                }

             }

          } else {

             visited_vertices[v] = color::BLACK;

          }

       }

       std::cout.flush();

    }

}

void DFS(const std::vector<std::vector<int>>& list_of_adjacency,
         std::vector<color>& visited_vertices,
         int start_vertex) {

   visited_vertices[start_vertex] = color::GRAY;

   std::cout << start_vertex + 1 << ' ';

   for (const int vertex : list_of_adjacency[start_vertex]) {

      if (visited_vertices[vertex] == color::WHITE) {

         DFS(list_of_adjacency, visited_vertices, vertex);

      }

   }

   visited_vertices[start_vertex] = color::BLACK;

}

void MainDFS(const std::vector<std::vector<int>>& list_of_adjacency, int start_vertex = 0) {

   std::vector<color> visited_vertices(list_of_adjacency.size(), color::WHITE);

   new_algorithm::DFS(list_of_adjacency, visited_vertices, start_vertex);

}

int main() {

   int number_of_vertices, number_of_edges;

   std::cin >> number_of_vertices >> number_of_edges;

   std::vector<std::pair<int, int>> list_of_edges(number_of_edges);

   for (auto& edge : list_of_edges) {

      std::cin >> edge.first >> edge.second;

   }

   int start_vertex;

   std::cin >> start_vertex;

   std::vector<std::vector<int>> list_of_adjacency(number_of_vertices);

   for(const auto& edge : list_of_edges) {

      list_of_adjacency[edge.first - 1].emplace_back(edge.second - 1);
      list_of_adjacency[edge.second - 1].emplace_back(edge.first - 1);

   }

   for(auto& vertex_adjacency : list_of_adjacency) {

      std::sort(vertex_adjacency.rbegin(), vertex_adjacency.rend());

   }

   MainDFS(list_of_adjacency, start_vertex - 1);

   std::cout.flush();

   return 0;
}
