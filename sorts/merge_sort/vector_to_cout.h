//
// Created by smarty on 15.02.2021.
//

#ifndef MERGE_SORT_VECTOR_TO_COUT_H
#define MERGE_SORT_VECTOR_TO_COUT_H

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os,const std::vector<int>& vec) {
    os << "[";
    bool is_first = true;
    for (const int& element : vec) {
        if (is_first) {
            is_first = false;
            os << element;
            continue;
        }
        os << ", ";
        os << element;
    }

    os << "]";

    return os;
}

#endif //MERGE_SORT_VECTOR_TO_COUT_H
