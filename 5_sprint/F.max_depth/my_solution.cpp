//
// Created by Олег Аксененко on 10.04.2021.
//
#include "solution_tree.h"
#include <algorithm>

int Solution(const Node* root) {

   int prev_lhs_subtree_height = 0, prev_rhs_subtree_height = 0;

   if (root->left) {

      prev_lhs_subtree_height = Solution(root->left);

   }

   if (root->right) {

      prev_rhs_subtree_height = Solution(root->right);

   }

   if (!root->left && !root->right) {

      return 1;

   }

   return std::max(prev_lhs_subtree_height, prev_rhs_subtree_height) + 1;

}