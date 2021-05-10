//
// Created by Олег Аксененко on 09.04.2021.
//
#include "solution.h"
#include <iostream>

// ID удачной посылки: 50494174

int find_min_value_from_subtree(const Node* root) {

   int min = root->value;

   if (root->left) {

      root = root->left;
      min = root->value;

      while (root->right) {

         root = root->right;
         min = root->value;

      }

   }

   return min;

}

Node* remove(Node* root, const int value) {

   static Node* root_of_tree = root;

   if (!root) {

      return nullptr;

   }

   if (root->value == value) {

      bool have_two_child = root->left && root->right;
      bool have_one_child = root->left != nullptr ^ root->right != nullptr;
      bool have_no_child = root->left == nullptr && root->right == nullptr;

      if (have_no_child) {

         delete root;
         root = nullptr;

      } else if (have_one_child) {

         Node* tmp_node = root;

         if (root->left) {


            root = root->left;

         } else {

            root = root->right;

         }

         delete tmp_node;

      } else if (have_two_child) {

         root->value = find_min_value_from_subtree(root);
         root->left = remove(root->left, root->value);

      }

   } else if (value > root->value) {

      root->right = remove(root->right, value);

   } else {

      root->left = remove(root->left, value);

   }

   return root;

}