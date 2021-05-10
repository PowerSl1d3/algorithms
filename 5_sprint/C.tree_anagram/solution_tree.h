//
// Created by Олег Аксененко on 10.04.2021.
//

#ifndef C_TREE_ANAGRAM_SOLUTION_TREE_H
#define C_TREE_ANAGRAM_SOLUTION_TREE_H

struct Node{
    int value;
    const Node* left = nullptr;
    const Node* right = nullptr;
};
bool Solution(const Node* root);

#endif //C_TREE_ANAGRAM_SOLUTION_TREE_H
