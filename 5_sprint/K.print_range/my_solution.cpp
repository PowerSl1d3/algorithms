//
// Created by Олег Аксененко on 09.04.2021.
//
#include "solution_tree.h"
#include <iostream>

bool in_range(const int target, const int lhs_border, const int rhs_border) {

   return target >= lhs_border && target <= rhs_border;

}

void inorder_traversal(Node* root, const int L, const int R) {

   if (root->left != nullptr) {

      inorder_traversal(root->left, L, R);

   }

   if (in_range(root->value, L, R)) {

      std::cout << root->value << ' ';

   }

   if (root->right != nullptr) {

      inorder_traversal(root->right, L, R);

   }

}

void print_range(Node* root, int L, int R) {

   if (!root) {

      return;

   }

   if (in_range(root->value, L, R)) {

      inorder_traversal(root, L, R);

   } else {

      if (root->value < L && root->right) {

         print_range(root->right, L, R);

      } else if (root->value > R && root->left) {

         print_range(root->left, L, R);

      }

   }

}