#include <iostream>
#include "solution_tree.h"

int main() {

   Node root1, root2;
   root1.value = 1;
   root2.value = 1;

   Node lhs_root, rhs_root;
   lhs_root.value = 2;
   rhs_root.value = 2;

   root1.left = &lhs_root;
   root2.left = &rhs_root;

   /*Node lhs_root_lhs, lhs_root_rhs, rhs_root_lhs, rhs_root_rhs;

   lhs_root_lhs.value = 4;
   lhs_root_rhs.value = 3;

   rhs_root_lhs.value = 3;
   rhs_root_rhs.value = 4;

   root.left = &lhs_root;
   root.right = &rhs_root;

   lhs_root.left = &lhs_root_lhs;
   lhs_root.right = &lhs_root_rhs;
   rhs_root.left = &rhs_root_lhs;
   rhs_root.right = &rhs_root_rhs;*/

   std::cout << Solution(&root1, &root2);

   return 0;
}
