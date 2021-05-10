//
// Created by Олег Аксененко on 10.04.2021.
//
#include "solution_tree.h"
#include <string>

void LRM(const Node* root, std::string& answer) {

   if (root->left) {

      LRM(root->left, answer);

   }

   if (root->right) {

      LRM(root->right, answer);

   }

   answer += std::to_string(root->value);

}

void MLR(const Node* root, std::string& answer) {

   answer += std::to_string(root->value);

   if (root->left) {

      MLR(root->left, answer);

   }

   if (root->right) {

      MLR(root->right, answer);

   }

}

void LMR(const Node* root, std::string& answer) {

   if (root->left) {

      LMR(root->left, answer);

   }

   answer += std::to_string(root->value);

   if (root->right) {

      LMR(root->right, answer);

   }

}

bool Solution(const Node* root1, const Node* root2) {

   std::string first_tree_structure, second_tree_structure;

   LRM(root1, first_tree_structure);
   LMR(root1, first_tree_structure);
   MLR(root1, first_tree_structure);
   LRM(root2, second_tree_structure);
   LMR(root2, second_tree_structure);
   MLR(root2, second_tree_structure);

   return first_tree_structure == second_tree_structure;

}