#ifndef Y1S2_ALG_SD2_DECK_H
#define Y1S2_ALG_SD2_DECK_H

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

    void pushBack(double);

    void pushFront(double);
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

void Deck::pushBack(double value) {
    Node* node = new Node(value);
    if (this->isEmpty()) {
        this->first = node;
        this->last = node;
        return;
    }
    this->last->connectNext(node);
    this->last = node;
}

void Deck::pushFront(double value) {
    Node* node = new Node(value);
    if (this->isEmpty()) {
        this->first = node;
        this->last = node;
        return;
    }
    node->connectNext(this->first);
    this->first = node;
}

#endif //Y1S2_ALG_SD2_DECK_H
