//
// Created by Олег Аксененко on 10.04.2021.
//
#include "solution_tree.h"
#include <algorithm>

int abs(int x) {

   return (x < 0) ? -x : x;

}

int get_subtree_height(const Node* root) {

   int lhs_subtree_height, rhs_subtree_height;

   if (root->left) {

      lhs_subtree_height = get_subtree_height(root->left);

   }

   if (root->right) {


      rhs_subtree_height = get_subtree_height(root->right);

   }

   if (!root->left && !root->right) {

      return 1;

   }

   return std::max(lhs_subtree_height, rhs_subtree_height) + 1;

}

bool Solution(const Node* root) {

   if (!root) {

      return true;

   }

   int lhs_subtree_height = 0;
   int rhs_subtree_height = 0;
   bool prev_lhs_subtree_answer = true;
   bool prev_rhs_subtree_answer = true;

   if (root->left) {

      prev_lhs_subtree_answer = Solution(root->left);
      lhs_subtree_height = get_subtree_height(root->left);

   }

   if (root->right) {

      prev_rhs_subtree_answer = Solution(root->right);
      rhs_subtree_height = get_subtree_height(root->right);

   }

   if (!prev_lhs_subtree_answer || !prev_rhs_subtree_answer) {

      return false;

   } else if (abs(lhs_subtree_height - rhs_subtree_height) > 1) {

      return false;

   }

   return true;

}