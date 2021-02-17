#include <iostream>
#include "solution.h"

int main() {

    Node tail("tail", nullptr);
    Node node3("node3", &tail);
    Node node2("node2", &node3);
    Node node1("node1", &node2);
    Node* head = &node1;

    Node* new_head = solution(head, 0);
    Node* new_head2 = solution(new_head, 1);
    Node* delete_tail = solution(new_head2, 1);

    return 0;
}
