//
// Created by Олег Аксененко on 08.04.2021.
//
#include "solution_tree.h"
#include <string>

int solution(const Node* root, std::string prev_value = "") {

   static int sum = 0;

   prev_value += std::to_string(root->value);

   if (root->left) {

      solution(root->left, prev_value);

   }

   if (root->right) {

      solution(root->right, prev_value);

   }

   if (root->left == nullptr && root->right == nullptr) {

      sum += stoi(prev_value);

   }

   return sum;

}

int Solution(const Node* root) {

   return solution(root);

}