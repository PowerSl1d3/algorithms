#include <iostream>
#include "solution.h"
#include <cassert>

int main() {

    Node tail("tail", nullptr);
    Node node3("node3", &tail);
    Node node2("node2", &node3);
    Node node1("node1", &node2);
    Node* head = &node1;

    assert(solution(head, "node1") == 0);
    assert(solution(head, "tail") == 3);
    assert(solution(head, "qjlewjgf") == -1);

    return 0;
}
