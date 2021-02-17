#include <iostream>
#include "solution.h"

int main() {

    Node tail("tail", nullptr, nullptr);
    Node node3("node3", &tail, nullptr);
    Node node2("node2", &node3, nullptr);
    Node node1("node1", &node2, nullptr);
    Node* head = &node1;
    node2.prev = &node1;
    node3.prev = &node2;
    tail.prev = &node3;

    Node* new_head = solution(head);

    return 0;
}
