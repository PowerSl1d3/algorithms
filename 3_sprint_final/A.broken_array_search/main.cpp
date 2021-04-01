#include <iostream>
#include <vector>
#include <utility>

//ID удачной посылки: 49430789

std::pair<std::vector<int>, int> get_array_and_element_from_cin() {

   int count, destination_element;

   std::cin >> count >> destination_element;

   std::vector<int> array(count);

   for (int& element : array) {
      std::cin >> element;
   }

   return {std::move(array), destination_element};

}

int binary_search(const std::vector<int>& array, const int begin, const int end, const int element) {

   if (end <= begin) {
      return -1;
   }

   int mid = begin + (end - begin) / 2;

   if (element == array[mid]) {

      return mid;

   } else if (element < array[mid]) {

      return binary_search(array, begin, mid, element);

   } else {

      return binary_search(array, mid + 1, end, element);

   }

}

bool is_ascending_sequence(const int begin, const int mid, const int end) {

   return begin <= mid && mid <= end;
   
}

bool in_range(const int begin, const int end, const int element) {

   return element >= begin && element <= end;

}

/*
 * Not relevant to the task.
 * Я думал о подобной реализации, когда начинал выполнение задачи, но она показалась мне довольно громздкой, даже на уровне идеи,
 * да и до конца не понимал как анализировать массив и в какой половине искать, поэтому долго и упорно откидывал мысль о подобной реализации)
 * но ваша подсказка дала толчок и теперь идея реализована в коде.
 */

int binary_search_it_two_ascending_sequence(const std::vector<int>& array, const int begin, const int end, const int element) {

   if (end <= begin) {
      return -1;
   }

   int mid = begin + (end - begin) / 2;

   //сокращение asc - ascending

   bool full_array_is_asc_sequence = is_ascending_sequence(array[begin], array[mid], array[end - 1]);
   bool lhs_is_asc_sequence = is_ascending_sequence(array[begin], array[mid], array[mid]);
   bool rhs_is_asc_sequence = is_ascending_sequence(array[mid], array[end - 1], array[end - 1]);
   bool element_in_lhs_sequence = in_range(array[begin], array[mid - 1], element);
   bool element_in_rhs_sequence = in_range(array[mid], array[end - 1], element);

   /*
    * Если входной массив является простой отсортированной последовательностью, то запускается бинарный поиск
    */
   if (full_array_is_asc_sequence) {

      return binary_search(array, begin, end, element);

   } else if (lhs_is_asc_sequence && element_in_lhs_sequence) { //Иначе, если левая половина - возрастающая последовательность и элемент в её диапазоне, то будем искать в ней

      return binary_search(array, begin, mid + 1, element);

   } else if (lhs_is_asc_sequence && !element_in_lhs_sequence) { //Если левая половина - возрастающая последовательность, но элемент не в ней, то спускаемся на уровень рекурсии ниже

      return binary_search_it_two_ascending_sequence(array, mid, end, element);

   } else if (rhs_is_asc_sequence && element_in_rhs_sequence) { //Иначе, если левая половина возрастающая последовательность и элемент в её диапазоне, то будем искать в ней

      return binary_search(array, mid + 1, end, element);

   } else if (rhs_is_asc_sequence && !element_in_rhs_sequence) { //Если правая половина - возрастающая последовательность, но элемент не в ней, то спускаемся на уровень рекурсии ниже

      return binary_search_it_two_ascending_sequence(array, begin, mid, element);

   }

}

int main() {

   const auto [array, destination_element] = get_array_and_element_from_cin();

   std::cout << binary_search_it_two_ascending_sequence(array, 0, array.size(), destination_element);

   return 0;
}
