//
// Created by Олег Аксененко on 13.03.2021.
//
#include "merge_sort.h"
#include <algorithm>

std::vector<int> merge(CIterator left_begin, CIterator left_end, CIterator right_begin, CIterator right_end) {

   std::vector<int> merging_elements;
   merging_elements.reserve(left_end - left_begin + right_end - right_begin);

   while (left_begin != left_end && right_begin != right_end) {
      if (*left_begin < *right_begin) {
         merging_elements.push_back(*left_begin++);
      } else {
         merging_elements.push_back(*right_begin++);
      }
   }

   if (left_begin == left_end) {
      while (right_begin != right_end) {
         merging_elements.push_back(*right_begin++);
      }
   }

   if (right_begin == right_end) {
      while (left_begin != left_end) {
         merging_elements.push_back(*left_begin++);
      }
   }

   return merging_elements;

}

void merge_sort(Iterator begin, Iterator end) {

   if (end - begin < 2) {
      return;
   }

   Iterator mid = begin + (end - begin) / 2;
   merge_sort(begin, mid);
   merge_sort(mid, end);

   std::vector<int> merging_elements = merge(begin, mid, mid, end);
   std::copy(merging_elements.begin(), merging_elements.end(), begin);

}
