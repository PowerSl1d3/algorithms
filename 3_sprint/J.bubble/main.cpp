#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec ) {

   for (auto element : vec) {
       os << element << ' ';
   }

   return os;

}

void bubble_sort(std::vector<int>& array) {

    bool was_changed = false;

    for (size_t i = 0; i < array.size(); ++i) {
        for (size_t j = 0; j < array.size() - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                was_changed = true;
            }
        }

        if (was_changed) {
            was_changed = false;
            std::cout << array << "\n";
        } else {
            return;
        }
    }

}

int main() {

    size_t size;

    std::cin >> size;

    std::vector<int> array(size);

    for (int& element : array) {
        std::cin >> element;
    }

    if (std::is_sorted(array.begin(), array.end())) {

        std::cout << array;

        return 0;

    }

    bubble_sort(array);

    return 0;
}
