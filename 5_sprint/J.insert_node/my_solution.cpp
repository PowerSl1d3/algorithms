//
// Created by Олег Аксененко on 09.04.2021.
//
#include "solution.h"

Node* insert(Node* root, int value) {

   if (!root) {

      root = new Node;
      root->value = value;
      return root;

   }

   if (value >= root->value) {

      if (!root->right) {

         root->right = new Node;
         root->right->value = value;

      } else {

         insert(root->right, value);

      }

   } else {

      if (!root->left) {

         root->left = new Node;
         root->left->value = value;

      } else {

         insert(root->left, value);

      }

   }

   return root;

}