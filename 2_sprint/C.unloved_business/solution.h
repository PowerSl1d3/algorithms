//
// Created by smarty on 16.02.2021.
//

#ifndef C_UNLOVED_BUSINESS_SOLUTION_H
#define C_UNLOVED_BUSINESS_SOLUTION_H

#include <string>

struct Node {
    std::string value;
    Node* next;
    Node(const std::string &value, Node* next);
};
Node* solution(Node* head, int idx);

#endif //C_UNLOVED_BUSINESS_SOLUTION_H
