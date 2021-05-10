//
// Created by Олег Аксененко on 05.04.2021.
//
#include <algorithm>
#include "solution_tree.h"

int Solution(const Node* root) {

   int left, right, middle;

   if (root->left != nullptr) {

      left = Solution(root->left);

   } else {

      left = root->value;

   }

   middle = root->value;

   if (root->right != nullptr) {

      right = Solution(root->right);

   } else {

      right = root->value;

   }

   return std::max(std::max(left, right), middle);

}