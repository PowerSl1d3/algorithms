//
// Created by smarty on 16.02.2021.
//

#ifndef E_THE_OPPOSITE_IS_TRUE_SOLUTION_H
#define E_THE_OPPOSITE_IS_TRUE_SOLUTION_H

#include <string>

struct Node {
    Node(const std::string &value, Node* next, Node* prev) : value(value), next(next), prev(prev) {}

    std::string value;
    Node* next;
    Node* prev;
};
Node* solution(Node* head);

#endif //E_THE_OPPOSITE_IS_TRUE_SOLUTION_H
