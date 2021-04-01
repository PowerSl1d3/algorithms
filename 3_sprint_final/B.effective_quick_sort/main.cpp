#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <tuple>
#include <ctime>

//ID удачной посылки: 49389710

/*
 * Единственный шаг, который, как мне кажется, стоит объяснить, это то что при выполнении
 * функции partition, при выборе опорного элемента, он ставится на начало текущего обозреваемого
 * диапазона массива. После же выполнения переставления элементов местами, опорный элемент помещается
 * сразу за тем местом, где нарушился порядок следования указателей на левую границу диапазона и правую.
 * Для выбора опорного элемента используется стандартный генератор случайных чисел, который при каждом вызове
 * устанавливается в новое состояние(то есть изменяет границы, в диапазоне которых генерирует случайные числа).
 */

struct Player {
   std::string name;
   int count_of_completed_tasks;
   int penalty_points;
   auto tiePlayer() const {
      return std::tie(count_of_completed_tasks, penalty_points, name);
   }
   bool operator<(const Player& rhs) const {
      return tiePlayer() < rhs.tiePlayer();
   }
    bool operator>(const Player& rhs) const {
       return tiePlayer() > rhs.tiePlayer();
    }
};

std::istream& operator>>(std::istream& is, Player& player) {

   is >> player.name >> player.count_of_completed_tasks >> player.penalty_points;
   player.count_of_completed_tasks *= -1;

   return is;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {

   os << player.name;

   return os;
}

class Random {
private:
    /*Теперь комментарий "поправить потом" не требуется:)
     * Я понимал, что создание объекта в каждом рекурсивном вызове дорогостоящая операция,
     * но не на столько, что по итогу статическое поле ускорило код примерно в 5 раз.
     * Вывод: нужно просто брать и тестировать)
     */
    static std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;
public:
    Random(int lower_bound, int upper_bound) {
       distribution = std::uniform_int_distribution<int>(lower_bound, upper_bound);
    }

    int get_random_number(void) {
       return distribution(generator);
    }
};

std::mt19937 Random::generator = std::mt19937(time(0));

int partition(std::vector<Player>& array, const int range_begin, const int range_end) {

   int pivot = Random(range_begin, range_end).get_random_number();
   std::swap(array[range_begin], array[pivot]);

   int i = range_begin + 1;
   int j = range_end;

   while (true) {
      while (i <= range_end && array[i] < array[range_begin]) {
         ++i;
      }
      while (j >= range_begin && array[j] > array[range_begin]) {
         --j;
      }
      if (i >= j) {
         break;
      } else {
         std::swap(array[i], array[j]);
         ++i;
         --j;
      }
   }
   std::swap(array[range_begin], array[i - 1]);

   return i - 1;

}

void quick_sort(std::vector<Player>& array, const int range_begin, const int range_end) {

   if (range_begin < range_end) {
      int pivot = partition(array, range_begin, range_end);
      quick_sort(array, range_begin, pivot - 1);
      quick_sort(array, pivot + 1, range_end);
   }

}

int main() {

   int count_of_players;

   std::cin >> count_of_players;

   std::vector<Player> players(count_of_players);

   for(Player& player : players) {
      std::cin >> player;
   }

   quick_sort(players, 0, players.size() - 1);

   for(const Player& player : players) {
      std::cout << player << "\n";
   }

   return 0;
}
