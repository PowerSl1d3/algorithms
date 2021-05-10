//
// Created by Олег Аксененко on 09.04.2021.
//

#ifndef J_INSERT_NODE_SOLUTION_H
#define J_INSERT_NODE_SOLUTION_H
struct Node {
    int value;
    Node* left;
    Node* right;
};
Node* insert(Node* root, int value);
#endif //J_INSERT_NODE_SOLUTION_H
