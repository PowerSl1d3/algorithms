//
// Created by Олег Аксененко on 09.04.2021.
//

#ifndef K_PRINT_RANGE_SOLUTION_TREE_H
#define K_PRINT_RANGE_SOLUTION_TREE_H
struct Node{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};
void print_range(Node* root, int L, int R);
#endif //K_PRINT_RANGE_SOLUTION_TREE_H
