//
// Created by Олег Аксененко on 10.04.2021.
//

#ifndef D_TWIN_TREES_SOLUTION_TREE_H
#define D_TWIN_TREES_SOLUTION_TREE_H

struct Node{
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
};
bool Solution(const Node* root1, const Node* root2);

#endif //D_TWIN_TREES_SOLUTION_TREE_H
