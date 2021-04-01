#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& array, const int begin, const int end, const int element) {

    if (end <= begin) {
        return -1;
    }

    int mid = begin + (end - begin) / 2;

    if (element <= array[mid]) {

        while (array[mid] >= element) {
            --mid;
        }

        return mid + 2;

    } else {

        return binary_search(array, mid + 1, end, element);

    }

}

int main() {

    int count, cost;

    std::cin >> count;

    std::vector<int> input_array(count);

    for (int& element : input_array) {
        std::cin >> element;
    }

    std::cin >> cost;

    std::cout << binary_search(input_array, 0, input_array.size(), cost)
            << ' ' << binary_search(input_array, 0, input_array.size(), 2 * cost);

    return 0;
}
