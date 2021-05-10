//
// Created by Олег Аксененко on 08.04.2021.
//

#ifndef H_NUMERIC_PATH_SOLUTION_TREE_H
#define H_NUMERIC_PATH_SOLUTION_TREE_H

struct Node{
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
};
int Solution(const Node* root);

#endif //H_NUMERIC_PATH_SOLUTION_TREE_H
