#include <iostream>
#include "solution.h"

int main() {

    Node tail("Oleg", nullptr);
    Node node1("Is", &tail);
    Node node2("Name", &node1);
    Node node3("My", &node2);

    solution(&node3);

    return 0;
}
