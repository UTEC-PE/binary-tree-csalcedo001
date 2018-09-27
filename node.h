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
        if (left)
            left->print();

        cout << data << " ";

        if (right)
            right->print();
    }
    int height() {
        int h_left = left ? left->height() : 0, h_right = right ? right->height() : 0;

        return 1 + (h_left > h_right ? h_left : h_right);
    }
};

#endif
