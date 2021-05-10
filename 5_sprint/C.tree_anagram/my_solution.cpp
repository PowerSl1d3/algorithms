//
// Created by Олег Аксененко on 10.04.2021.
//
#include "solution_tree.h"
#include <string>

std::string solution_lmr(const Node* root) {

   std::string answer;

   if (root->left) {

      answer += solution_lmr(root->left);

   }

   answer += std::to_string(root->value);

   if (root->right) {

      answer += solution_lmr(root->right);

   }

   return answer;

}

std::string solution_rml(const Node* root) {

   std::string answer;

   if (root->right) {

      answer += solution_rml(root->right);

   }

   answer += std::to_string(root->value);

   if (root->left) {

      answer += solution_rml(root->left);

   }

   return answer;

}

bool Solution(const Node* root) {

   std::string lhs_subtree_nodes, rhs_subtree_nodes;

   if (root->left) {

      lhs_subtree_nodes = solution_lmr(root->left);

   }

   if (root->right) {

      rhs_subtree_nodes = solution_rml(root->right);

   }

   return lhs_subtree_nodes == rhs_subtree_nodes;

}