#include <iostream>
#include <vector>
#include <stdexcept>
#include <tuple>
#include <set>
#include <algorithm>
#include <cstdint>

//ID удачной посылки: 52038162

/*
 * Временная сложность алгоритма: O(V*E),
 * где V - количество вершин в графе,
 * а E - количество рёбер в графе
 * Пространственная сложность алгоритма:
 * O(E*2V)
 * Алгоритм минимального(максимального) остовного дерева
 * перебирает все рёбра, смежные с веришнами, которые уже находятся в остовном дереве
 * и добавляет те, которые ещё в нём не находятся и имеют минимальный(максимальный вес), а затем добавляет
 * новые смежные рёбра от добавленной вершины и т.д.
 */

struct edge {

    int from_;
    int to_;
    int weight_;

    edge() = default;

    edge(const int from, const int to, const int weight):
    from_(from),
    to_(to),
    weight_(weight)
    {}

};

bool operator<(const edge& lhs, const edge& rhs) {

   return std::tie(lhs.weight_, lhs.from_, lhs.to_) <
          std::tie(rhs.weight_, rhs.from_, rhs.to_);

}

void AddVertex(const int new_vertex,
               std::vector<bool>& used_vertices,
               const std::vector<std::vector<std::pair<int,int>>>& list_of_adjacency,
               std::set<edge>& used_edges) {

      used_vertices[new_vertex] = true;

      for (const std::pair<int, int>& adjacency_vertex: list_of_adjacency[new_vertex]) {

         if (!used_vertices[adjacency_vertex.first]) {

            used_edges.insert({new_vertex, adjacency_vertex.first, adjacency_vertex.second});

         }

      }


}

edge ExtractMinimum(std::set<edge>& used_edges) {

   return used_edges.extract(used_edges.begin()).value();

}

edge ExtractMaximum(std::set<edge>& used_edges) {

   return used_edges.extract(std::prev(used_edges.end())).value();

}

std::vector<edge> SpanningTree(
        const std::vector<std::vector<std::pair<int,int>>>& list_of_adjacency) {

   std::vector<bool> used_vertices(list_of_adjacency.size(), false);
   std::set<edge> used_edges;
   std::vector<edge> minimum_spanning_tree;
   uint32_t current_unused_vertices = list_of_adjacency.size();

   //O(E)
   AddVertex(0, used_vertices, list_of_adjacency, used_edges);
   --current_unused_vertices;

   //O(V) * O(E)
   while (current_unused_vertices && !used_edges.empty()) {

      //O(log(E))
      edge e = ExtractMaximum(used_edges);

      //O(E)
      if (!used_vertices[e.to_]) {

         //O(1) амортизированное
         minimum_spanning_tree.push_back(e);
         //O(E)
         AddVertex(e.to_, used_vertices, list_of_adjacency, used_edges);
         --current_unused_vertices;

      }

   }

   if (current_unused_vertices) {

      throw std::runtime_error("Oops! I did it again\n");

   }

   return minimum_spanning_tree;

}

int main() {

   int number_of_vertices, number_of_edges;

   std::cin >> number_of_vertices >> number_of_edges;

   std::vector<edge> list_of_edges(number_of_edges);

   for (auto& edge : list_of_edges) {

      std::cin >> edge.from_ >> edge.to_ >> edge.weight_;

   }

   std::vector<std::vector<std::pair<int, int>>> list_of_adjacency(number_of_vertices);

   for(const auto& edge : list_of_edges) {

      list_of_adjacency[edge.from_ - 1].emplace_back(edge.to_ - 1, edge.weight_);
      list_of_adjacency[edge.to_ - 1].emplace_back(edge.from_ - 1, edge.weight_);

   }

   std::vector<edge> maximum_spanning_tree;

   try {

      maximum_spanning_tree = SpanningTree(list_of_adjacency);

   } catch (std::runtime_error& e) {
      std::cout << e.what();
      std::cout.flush();

      return 0;
   }

   int sum = 0;

   for (const auto& vertex : maximum_spanning_tree) {

      sum += vertex.weight_;

   }


   std::cout << sum;

   std::cout.flush();

   return 0;
}
