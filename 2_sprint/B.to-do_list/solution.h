//
// Created by smarty on 15.02.2021.
//

#ifndef B_TO_DO_LIST_SOLUTION_H
#define B_TO_DO_LIST_SOLUTION_H

#include <string>

struct Node {
    std::string value;
    Node* next;
    Node(const std::string &value, Node* next);
};

void solution(Node* head);

#endif //B_TO_DO_LIST_SOLUTION_H
