//
// Created by Олег Аксененко on 06.04.2021.
//
#include "solution_tree.h"
#include <algorithm>

int get_max_value_from_subtree(const Node* root) {

   int left = root->value;
   int right = root->value;

   if (root->left) {

      left = get_max_value_from_subtree(root->left);

   }

   if (root->right) {

      right = get_max_value_from_subtree(root->right);

   }

   return std::max(std::max(left, right), root->value);

}

bool Solution(const Node* root) {

   if (root->left) {

      if (!Solution(root->left)) {

         return false;

      }
      int left_subtree = get_max_value_from_subtree(root->left);

      if (left_subtree >= root->value) {

         return false;

      }

   }

   if (root->right) {

      if (!Solution(root->right)) {

         return false;

      }
      int right_subtree = get_max_value_from_subtree(root->right);

      if (right_subtree <= root->value) {

         return false;

      }

   }

   return true;

}