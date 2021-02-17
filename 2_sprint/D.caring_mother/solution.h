//
// Created by smarty on 16.02.2021.
//

#ifndef D_CARING_MOTHER_SOLUTION_H
#define D_CARING_MOTHER_SOLUTION_H

#include <string>

struct Node {
    std::string value;
    Node* next;
    Node(const std::string &value, Node* next);
};
int solution(Node *head, const std::string& elem);

#endif //D_CARING_MOTHER_SOLUTION_H
