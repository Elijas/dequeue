#ifndef Y1S2_ALG_SD2_DECK_H
#define Y1S2_ALG_SD2_DECK_H

struct Node {
    double data;
    Node *previous = nullptr;
    Node *next = nullptr;

    void connectNext(Node *next);
};

void Node::connectNext(Node *next) {
    this->next = next;
    next->previous = this;
}

#endif //Y1S2_ALG_SD2_DECK_H
