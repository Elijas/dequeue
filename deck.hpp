#ifndef Y1S2_ALG_SD2_DECK_H
#define Y1S2_ALG_SD2_DECK_H

#include <sstream>

struct Node {
    double data;
    Node *previous = nullptr;
    Node *next = nullptr;

    void connectNext(Node *next);

    Node(double value) {
        this->data = value;
    }
};

void Node::connectNext(Node *next) {
    this->next = next;
    next->previous = this;
}

struct Deck {
    Node *first = nullptr;
    Node *last = nullptr;
public:
    bool isEmpty();

    double peekFirst();

    double peekLast();

    void pushFront(double);

    void pushBack(double);

    void deleteFirst();

    void deleteLast();

    std::string toString();
};

bool Deck::isEmpty() {
    return this->first == nullptr && this->last == nullptr;
}

double Deck::peekFirst() {
    return this->first->data;
}

double Deck::peekLast() {
    return this->last->data;
}

void Deck::pushFront(double value) {
    Node *node = new Node(value);
    if (this->isEmpty()) {
        this->first = node;
        this->last = node;
        return;
    }
    node->connectNext(this->first);
    this->first = node;
}

void Deck::pushBack(double value) {
    Node *node = new Node(value);
    if (this->isEmpty()) {
        this->first = node;
        this->last = node;
        return;
    }
    this->last->connectNext(node);
    this->last = node;
}

void Deck::deleteFirst() {
    if (this->isEmpty())
        return;

    Node *node = this->first;
    if (this->first->next != nullptr) {
        this->first = this->first->next;
        this->first->previous = nullptr;
    } else {
        this->first = nullptr;
        this->last = nullptr;
    }
    delete node;
}

void Deck::deleteLast() {
    if (this->isEmpty())
        return;

    Node *node = this->last;
    if (this->last->previous != nullptr) {
        this->last = this->last->previous;
        this->last->next = nullptr;
    } else {
        this->first = nullptr;
        this->last = nullptr;
    }
    delete node;
}

std::string Deck::toString() {
    if (this->isEmpty())
        return "empty";

    std::stringstream ss;
    Node *node = this->first;
    while (node) {
        ss << node->data << ' ';
        node = node->next;
    }
    return ss.str();
//    return "test";
}

#endif //Y1S2_ALG_SD2_DECK_H
