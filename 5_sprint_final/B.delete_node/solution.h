//
// Created by Олег Аксененко on 09.04.2021.
//

#ifndef B_DELETE_NODE_SOLUTION_H
#define B_DELETE_NODE_SOLUTION_H

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node* remove(Node* root, int key);
void inorder_traversal(const Node* root);

#endif //B_DELETE_NODE_SOLUTION_H
