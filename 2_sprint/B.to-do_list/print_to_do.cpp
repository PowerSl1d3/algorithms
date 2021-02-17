//
// Created by smarty on 15.02.2021.
//

#include "solution.h"
#include <string>
#include <iostream>

/*Node::Node(const std::string &value_, Node *next_) :
value(value_),
next(next_)
{}*/

void solution(Node* head) {
    while (head != nullptr) {
        std::cout << head->value << "\n";
        head = head->next;
    }
}