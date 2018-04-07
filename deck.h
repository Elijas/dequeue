#ifndef Y1S2_ALG_SD2_DECK_H
#define Y1S2_ALG_SD2_DECK_H

struct Node {
    double data;
    Node *previous = nullptr;
    Node *next = nullptr;
};

class Deck {
    Node *first = nullptr;
    Node *last = nullptr;
public:
    bool isEmpty();
};

bool Deck::isEmpty() {
    return this->first == nullptr && this->last == nullptr;
}

#endif //Y1S2_ALG_SD2_DECK_H
