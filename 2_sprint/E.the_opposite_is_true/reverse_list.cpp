//
// Created by smarty on 16.02.2021.
//

#include "solution.h"
#include <string>

Node* solution(Node* head) {
    while (head->next != nullptr) {
        std::swap(head->next, head->prev);
        head = head->prev;
    }
    std::swap(head->next, head->prev);
    return head;
}