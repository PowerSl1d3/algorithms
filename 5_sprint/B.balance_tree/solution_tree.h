//
// Created by Олег Аксененко on 10.04.2021.
//

#ifndef B_BALANCE_TREE_SOLUTION_TREE_H
#define B_BALANCE_TREE_SOLUTION_TREE_H

struct Node{
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
};
bool Solution(const Node* root);

#endif //B_BALANCE_TREE_SOLUTION_TREE_H
