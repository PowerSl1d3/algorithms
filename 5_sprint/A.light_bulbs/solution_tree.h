//
// Created by Олег Аксененко on 05.04.2021.
//

#ifndef A_LIGHT_BULBS_SOLUTION_TREE_H
#define A_LIGHT_BULBS_SOLUTION_TREE_H

struct Node{
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
};
int Solution(const Node* root);

#endif //A_LIGHT_BULBS_SOLUTION_TREE_H
