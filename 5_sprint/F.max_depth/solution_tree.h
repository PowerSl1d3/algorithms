//
// Created by Олег Аксененко on 10.04.2021.
//

#ifndef F_MAX_DEPTH_SOLUTION_TREE_H
#define F_MAX_DEPTH_SOLUTION_TREE_H

struct Node{
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
};
int Solution(const Node* root);

#endif //F_MAX_DEPTH_SOLUTION_TREE_H
