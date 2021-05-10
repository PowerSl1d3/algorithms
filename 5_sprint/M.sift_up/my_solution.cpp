//
// Created by Олег Аксененко on 16.04.2021.
//
#include <vector>
#include "solution.h"

int siftUp(std::vector<int>& heap, int idx) {

   if (idx == 1) {

      return 1;

   }

   int parent_idx = idx / 2;

   if (heap[parent_idx] < heap[idx]) {

      std::swap(heap[parent_idx], heap[idx]);
      return siftUp(heap, parent_idx);

   }

   return idx;

}