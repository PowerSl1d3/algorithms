//
// Created by Олег Аксененко on 13.03.2021.
//

#ifndef K_MERGE_SORT_MERGE_SORT_H
#define K_MERGE_SORT_MERGE_SORT_H
#include <vector>

using Iterator = std::vector<int>::iterator;
using CIterator = std::vector<int>::const_iterator;
std::vector<int> merge(CIterator left_begin, CIterator left_end, CIterator right_begin, CIterator right_end);
void merge_sort(Iterator begin, Iterator end);

#endif //K_MERGE_SORT_MERGE_SORT_H
