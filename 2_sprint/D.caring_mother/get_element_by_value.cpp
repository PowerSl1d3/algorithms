//
// Created by smarty on 16.02.2021.
//

#include "solution.h"
#include <string>

/*Node::Node(const std::string& value_, Node* next_)
: value(value_)
, next(next_)
{}*/

int solution(Node *head, const std::string& elem) {

    int index = 0;

    while (head != nullptr) {
        if (head->value == elem) {
            return index;
        }
        ++index;
        head = head->next;
    }

    return -1;
}