#include <iostream>
#include "solution_tree.h"

int main() {

   Node* root = new Node;
   root->value = 1;

   Node* node1 = new Node;
   node1->value = 2;
   Node* node2 = new Node;
   node2->value = 0;

   root->left = node1;
   root->right = node2;

   Node* node3 = new Node;
   node3->value = 3;
   Node* node4 = new Node;
   node4->value = 6;

   node2->left = node3;
   node2->right = node4;

   Node* node5 = new Node;
   node5->value = 1550;
   Node* node6 = new Node;
   node6->value = 6;

   node1->left = node5;
   node3->left = node5;

   Node* node7 = new Node;
   node7->value = 1800;
   /*Node* node8 = new Node;
   node8->value = 2200;*/

   node5->left = node7;
   /*node2->right = node8;

    Node* node9 = new Node;
    node9->value = 3;

    node4->right = node9;

    Node* node10 = new Node;
    node10->value = 0;
    Node* node11 = new Node;
    node11->value = 1;

    node6->left = node10;
    node6->right = node11;*/

   std::cout << Solution(root);

   return 0;
}
