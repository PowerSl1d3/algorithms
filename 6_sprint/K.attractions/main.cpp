#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct vertex {

    int from;
    int to;
    int weight;

};

void relax(int start_vertex, int adjacency_vertex, std::vector<int>& dist, std::vector<int>& parent,
           const std::vector<std::vector<int>>& matrix_of_adjacency) {

   if (dist[adjacency_vertex] > dist[start_vertex] + matrix_of_adjacency[start_vertex][adjacency_vertex]) {

      dist[adjacency_vertex] = dist[start_vertex] + matrix_of_adjacency[start_vertex][adjacency_vertex];
      parent[adjacency_vertex] = start_vertex;

   }

}

int get_min_dist_from_not_visited_vertex(const std::vector<bool>& visited, const std::vector<int>& dist) {

   int current_vertex_with_min_dist = -1;
   int current_min_dist = std::numeric_limits<int>::max();

   for (size_t i = 0; i < visited.size(); ++i) {

      if (!visited[i] && dist[i] < current_min_dist) {

         current_vertex_with_min_dist = i;
         current_min_dist = dist[i];

      }

   }

   return current_vertex_with_min_dist;

}

std::vector<int> Dijkstra(const std::vector<std::vector<int>>& matrix_of_adjacency, int start_vertex) {

   std::vector<int> dist(matrix_of_adjacency.size(), std::numeric_limits<int>::max());
   std::vector<int> parent(matrix_of_adjacency.size(), -1);
   std::vector<bool> visited(matrix_of_adjacency.size(), false);

   dist[start_vertex] = 0;

   while (true) {

      int target_vertex = get_min_dist_from_not_visited_vertex(visited, dist);

      if (target_vertex == -1) {

         break;

      }

      visited[target_vertex] = true;

      for (size_t i = 0; i < matrix_of_adjacency.size(); ++i) {

         if (matrix_of_adjacency[target_vertex][i] != -1) {

            relax(target_vertex, i, dist, parent, matrix_of_adjacency);

         }

      }

   }

   return dist;

}

int main() {

   int number_of_vertices, number_of_edges;

   std::cin >> number_of_vertices >> number_of_edges;

   std::vector<vertex> list_of_edges(number_of_edges);

   for (auto& edge : list_of_edges) {

      std::cin >> edge.from >> edge.to >> edge.weight;

   }

   std::vector<std::vector<int>> matrix_of_adjacency(number_of_vertices, std::vector<int>(number_of_vertices, -1));

   for(const auto& edge : list_of_edges) {

      if ((matrix_of_adjacency[edge.from - 1][edge.to - 1] != -1 &&
      matrix_of_adjacency[edge.from - 1][edge.to - 1] > edge.weight) ||
      matrix_of_adjacency[edge.from - 1][edge.to - 1] == -1) {

         matrix_of_adjacency[edge.from - 1][edge.to - 1] = edge.weight;
         matrix_of_adjacency[edge.to - 1][edge.from - 1] = edge.weight;

      }
   }

   for (size_t i = 0; i < number_of_vertices; ++i) {

      auto dist = Dijkstra(matrix_of_adjacency, i);

      for (const int distance : dist) {

         if (distance == std::numeric_limits<int>::max()) {

            std::cout << -1 << ' ';
            continue;

         }

         std::cout << distance << ' ';

      }

      std::cout << '\n';

   }

   return 0;

}