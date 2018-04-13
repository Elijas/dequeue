#ifndef DECK_H
#define DECK_H

#include <sstream>

// Tiesinio dvikrypcio saraso elemento apibrezimas (bus naudojamas deko apibrezime)
struct Node {
    double data; // Elemento saugojamas skaicius
    Node *previous = NULL;
    Node *next = NULL;

    void connectNext(Node *next); // Prijungia kita dvikrypcio saraso elementa prie sio

    Node(double value) {
        this->data = value;
    }
};

void Node::connectNext(Node *next) {
    this->next = next;
    next->previous = this;
}

// Deko apibrezimas
struct Deck {
    Node *first = NULL;
    Node *last = NULL;
public:
    bool isEmpty(); // Tikrinimas, ar dekas neturi elementu

    double peekFirst(); // Pirmojo elemento skaiciaus gavimas

    double peekLast(); // Paskutiniojo elemento skaiciaus gavimas

    void pushFront(double); // Elemento idejimas i deko prieki

    void pushBack(double); // Elemento idejimas i deko gala

    void deleteFirst(); // Elemento pasalinimas is deko prieko

    void deleteLast(); // Elemento pasalinimas is deko galo

    std::string toString(); // Elementu skaiciaus saraso gavimas string pavidalu
};

bool Deck::isEmpty() {
    return this->first == NULL && this->last == NULL; // Tuscias dekas visada neturi pradzios ir pabaigos elementu
}

double Deck::peekFirst() {
    if (this->first == NULL)
        throw std::range_error; // Ismetama klaida nes bandyta gauti neegzistuojanti elementa
    return this->first->data;
}

double Deck::peekLast() {
    if (this->first == NULL)
        throw std::range_error; // Ismetama klaida nes bandyta gauti neegzistuojanti elementa
    return this->last->data;
}

void Deck::pushFront(double value) {
    Node *node = new Node(value); // Sukuriamas naujas elementas ir po to pridedamas prie deko priekio
    if (this->isEmpty()) { // Jei dekas buvo tuscias, tuomet nauju elementu uzpildoma jo pradzia ir pabaiga
        this->first = node;
        this->last = node;
        return;
    }
    node->connectNext(this->first);
    this->first = node;
}

void Deck::pushBack(double value) { // Analogiska pushFront funkcijai
    Node *node = new Node(value);
    if (this->isEmpty()) {
        this->first = node;
        this->last = node;
        return;
    }
    this->last->connectNext(node); // Pridedamas naujas elementas prie deko galo
    this->last = node;
}

void Deck::deleteFirst() {
    if (this->isEmpty()) // Nieko nedaroma jei dekas ir taip tuscias
        return;

    Node *node = this->first;
    if (this->first->next != NULL) { // Jei dekas turi antraji elementa
        this->first = this->first->next; // Dekas dabar prasideda jau nuo antrojo elemento
        this->first->previous = NULL; // Deko antrasis elementas tampa pirmuoju elementu
    } else { // Jei tai paskutinis elementas, tuomet istrinamos deke esancios rodykles i ta elementa
        this->first = NULL;
        this->last = NULL;
    }
    delete node;
}

void Deck::deleteLast() { // Analogiska deleteFirst funkcijai
    if (this->isEmpty())
        return;

    Node *node = this->last;
    if (this->last->previous != NULL) {
        this->last = this->last->previous;
        this->last->next = NULL;
    } else {
        this->first = NULL;
        this->last = NULL;
    }
    delete node;
}

std::string Deck::toString() { // Sudedami visi skaiciai i string teksto eilute
    if (this->isEmpty())
        return "empty";

    std::stringstream ss;
    Node *node = this->first;
    while (node) {
        ss << node->data << ' ';
        node = node->next;
    }
    return ss.str();
}

#endif //DECK_H
