//
// Created by Олег Аксененко on 06.04.2021.
//

#ifndef E_SEARCH_TREE_SOLUTION_TREE_H
#define E_SEARCH_TREE_SOLUTION_TREE_H

struct Node{
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
};
bool Solution(const Node* root);

#endif //E_SEARCH_TREE_SOLUTION_TREE_H
