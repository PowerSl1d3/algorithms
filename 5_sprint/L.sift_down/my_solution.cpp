//
// Created by Олег Аксененко on 16.04.2021.
//
#include <vector>
#include "solution.h"

int siftDown(std::vector<int>& heap, int idx) {

   int largest_idx;
   int lhs_idx = 2 * idx;
   int rhs_idx = 2 * idx + 1;

   if (heap.size() <= lhs_idx) {

      return idx;

   }

   if (rhs_idx <= heap.size() - 1 && heap[lhs_idx] < heap[rhs_idx]) {

      largest_idx = rhs_idx;

   } else {

      largest_idx = lhs_idx;

   }

   if (heap[idx] < heap[largest_idx]) {

      std::swap(heap[idx], heap[largest_idx]);
      return siftDown(heap, largest_idx);

   }

   return idx;

}