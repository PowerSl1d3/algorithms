#include <iostream>
#include <string>
#include <tuple>
#include <vector>

// ID удачной посылки: 50722332

/*
 * Сортировка кучей на основе массива
 * Релизована с поддержкой компараторов и шаблонов для произвольного типа данных
 */
struct Player {

    std::string login;
    int solved_tasks;
    int penalty_points;

    Player() :
    login(std::string()),
    solved_tasks(std::numeric_limits<int>::min()),
    penalty_points(std::numeric_limits<int>::min())
    {}

    Player(const Player& other) = default;

    Player& operator=(Player&& other) noexcept {

       login = std::move(other.login);
       solved_tasks = other.solved_tasks;
       penalty_points = other.penalty_points;

       other.solved_tasks = std::numeric_limits<int>::min();
       other.penalty_points = std::numeric_limits<int>::min();

       return *this;

    }

    bool operator<(const Player& rhs) const {

       return std::tie(solved_tasks, penalty_points, login) <
              std::tie(rhs.solved_tasks, rhs.penalty_points, rhs.login);

    }

};

template <typename T, typename Compare>
void siftUp(std::vector<T>& heap, const size_t idx, Compare comp = [](const T& lhs, const T& rhs) { return lhs < rhs; }) {

   if (idx == 1) {

      return;

   }

   size_t parent_idx = idx / 2;

   if (comp(heap[parent_idx], heap[idx])) {

      std::swap(heap[parent_idx], heap[idx]);
      siftUp(heap, parent_idx, comp);

   }

}

template <typename T, typename Compare>
void siftDown(std::vector<T>& heap, const size_t idx, Compare comp = [](const T& lhs, const T& rhs) { return lhs < rhs; }) {

   size_t largest_idx;
   size_t lhs_idx = 2 * idx;
   size_t rhs_idx = 2 * idx + 1;

   if (heap.size() <= lhs_idx) {

      return;

   }

   if (rhs_idx <= heap.size() - 1 && comp(heap[lhs_idx], heap[rhs_idx])) {

      largest_idx = rhs_idx;

   } else {

      largest_idx = lhs_idx;

   }

   if (comp(heap[idx], heap[largest_idx])) {

      std::swap(heap[idx], heap[largest_idx]);
      siftDown(heap, largest_idx, comp);

   }

}

template <typename T, typename Compare>
void heap_sort(std::vector<T>& array, Compare comp = [](const T& lhs, const T& rhs) { return lhs < rhs; }) {

   std::vector<T> heap(array.size() + 1);

   for (size_t i = 0; i < array.size(); ++i) {

      heap[i + 1] = std::move(array[i]);
      siftUp(heap, i + 1, comp);

   }

   for (size_t i = 0; i < array.size(); ++i) {

      array[array.size() - i - 1] = std::move(heap[1]);
      heap[1] = std::move(heap[heap.size() - i - 1]);
      siftDown(heap, 1, comp);

   }


}

int main() {

   size_t number_of_players;

   std::cin >> number_of_players;

   std::vector<Player> players(number_of_players);

   for (Player& player : players) {

      std::cin >> player.login >> player.solved_tasks >> player.penalty_points;

      player.solved_tasks *= -1;

   }

   heap_sort(players, [](const Player& lhs, const Player& rhs) {return lhs < rhs;});

   for (const Player& player : players) {

      std::cout << player.login << "\n";

   }

   return 0;
}