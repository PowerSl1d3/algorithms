//
// Created by smarty on 16.02.2021.
//

#include <string>
#include "solution.h"

/*Node::Node(const std::string& value_, Node* next_)
: value(value_)
, next(next_)
{}*/

Node* get_node(Node* node, int idx) {
    while (idx) {
        node = node->next;
        --idx;
    }

    return node;
}

Node* solution(Node* head, int idx) {
    if (idx == 0) {
        head = head->next;
        return head;
    }

    Node* prev = get_node(head, idx - 1);
    prev->next = prev->next->next;

    return head;
}
