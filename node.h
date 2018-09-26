#ifndef NODE
#define NODE

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    int data;

    Node *left;
    Node *right;

    Node () {
        left = right = nullptr;
    }
    Node (int data) : data(data) {
        left = right = nullptr;
    }

    void killSelf() {
        if (left)
            left->killSelf();

        if (right)
            right->killSelf();

        delete this;
    }
    void print() {
        cout << "[";

        if (left)
            left->print();

        cout << data;

        if (right)
            right->print();

        cout << "]";
    }
};

#endif
