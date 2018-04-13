#include <iostream>
#include <limits>

#include "deck.hpp"

// Funkcija kuri is vartotojo gauna raide
char readLetter() {
    char letter;
    do {
        std::cout << "[Enter a letter]: " << std::endl;
        std::cin.clear();
    } while (!(std::cin >> letter)); // Klaus raides tol kol bus ivesta raide
    return letter;
}

// Funkcija kuri is vartotojo gauna skaiciu
double readNumber() {
    double number;
    do {
        std::cout << "[Enter a number]: " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Leidziama ivesti tik skaicius
    } while (!(std::cin >> number)); // Klaus skaiciaus tol kol bus ivestas skaicius
    return number;
}

int main() {
    Deck deck;
    // Isvedamos instrukcijos
    std::cout << "Instructions: 'a' to add, 'd' to delete, 'x' to exit." << std::endl;
    std::cout << "Use capital letter to use dequeue's front instead of back." << std::endl;
    while (true) {
        // Isvedamas deko turinys
        std::cout << "[Deck] " << deck.toString() << std::endl;

        char command = readLetter();

        // Vykdomos komandos pagal ivesta raide
        if (std::tolower(command) == 'x') { // Programa isjungiama
            std::cout << "Closing the program." << std::endl;
            break;
        } else if (std::tolower(command) == 'd') { // Pasalinamas elementas
            if (std::isupper(command)) {
                deck.deleteFirst();
            } else {
                deck.deleteLast();
            }
        } else if (std::tolower(command) == 'a') { // Pridedamas elementas
            double number = readNumber();
            if (std::isupper(command))
                deck.pushFront(number);
            else
                deck.pushBack(number);
        } else { // Ivesta neteisinga komanda
            std::cout << "Incorrect input, no operation is performed" << std::endl;
        }
    }
    return 0;
}
