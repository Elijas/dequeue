#include <iostream>
#include <limits>

#include "deck.hpp"

char readLetter() {
    char letter;
    do {
        std::cout << "[Enter a letter]: " << std::endl;
        std::cin.clear();
    } while (!(std::cin >> letter));
    return letter;
}

double readNumber() {
    double number;
    do {
        std::cout << "[Enter a number]: " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!(std::cin >> number));
    return number;
}

int main() {
    Deck deck;
    std::cout << "Instructions: 'a' to add, 'd' to delete, 'x' to exit." << std::endl;
    std::cout << "Use capital letter to use front of deque." << std::endl;
    for (int i = 0; i < 100; i++) {
        std::cout << "[Deck] " << deck.toString() << std::endl;

        char command = readLetter();

        if (std::tolower(command) == 'x') {
            std::cout << "Closing the program." << std::endl;
            break;
        } else if (std::tolower(command) == 'd') {
            if (std::isupper(command)) {
                deck.deleteFirst();
            } else {
                deck.deleteLast();
            }
        } else if (std::tolower(command) == 'a') {
            double number = readNumber();
            if (std::isupper(command))
                deck.pushFront(number);
            else
                deck.pushBack(number);
        } else {
            std::cout << "Incorrect input, no operation is performed" << std::endl;
        }
    }
    return 0;
}
