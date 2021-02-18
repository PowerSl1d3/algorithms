#include <iostream>
#include <vector>
#include "vector_to_cout.h"

void insertion_sort(std::vector<int>& array) {
    for (size_t i = 0; i < array.size() - 1; i++) {
        size_t j = i + 1;
        while (j > 0 && array[j] < array[j - 1]) {
            std::swap(array[j], array[j - 1]);
            j--;
        }
    }
}

int main() {

    std::vector<int> array = {5, 6, 2, 9, 7, 0, 1, 4, 3, 8};

    insertion_sort(array);

    std::cout << array;

    return 0;
}
