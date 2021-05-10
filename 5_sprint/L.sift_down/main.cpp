#include <iostream>
#include <vector>
#include "solution.h"

int main() {

   std::vector<int> array = {0, 2, 3, 5, 4};

   std::cout << siftDown(array, 1);

   return 0;
}
