#include <iostream>
#include <vector>
#include "vector_to_cout.h"

std::vector<int> merge(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    size_t n = lhs.size();
    size_t m = rhs.size();

    std::vector<int> answer(lhs.size() + rhs.size());

    size_t i = 0, j = 0, k = 0;

    while (i < n || j < m) {
        if ( j == m || i < n && lhs[i] < rhs[j] ) {
            answer[k++] = lhs[i++];
        } else {
            answer[k++] = rhs[j++];
        }
    }

    return answer;
}

std::vector<int> merge_sort(const std::vector<int>& array) {

    size_t n = array.size();

    if (n <= 1) {
        return array;
    }

    std::vector<int> lhs, rhs;
    for (size_t i = 0; i <= n / 2 - 1; ++i) {
        lhs.push_back(array[i]);
    }
    for (size_t i = n / 2; i < n; ++i) {
        rhs.push_back(array[i]);
    }

    lhs = merge_sort(lhs);
    rhs = merge_sort(rhs);

    return merge(lhs, rhs);
}

int main() {

    std::vector<int> array = {5, 6, 2, 9, 7, 0, 1, 4, 3, 8};

    array = merge_sort(array);

    std::cout << array;

    return 0;
}
