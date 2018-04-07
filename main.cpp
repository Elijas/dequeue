#include <iostream>

#include "deck.h"

int main() {
    Node a{.data=1};
    Node b{.data=2};
    a.next = &b;
    std::cout << a.next->data;
}

int main_REPL() {
    while (true) {
        std::cout << "Current deck: empty" << std::endl;
        std::cout << "Instructions: 'a' to add, 'd' to delete, 'x' to exit. "
                  << "Use capital letter to use front of deque." << std::endl;
        char command;
        std::cin >> command;
        if (std::tolower(command) == 'x')
            break;
        else if (std::tolower(command) == 'd')
            std::cout << "D" << std::endl;
        else if (std::tolower(command) == 'a') {
            std::cout << "A" << std::endl;
        }
        else {
            std::cout << "Incorrect input, no operation is performed" << std::endl;
        }
    }
    return 0;
}