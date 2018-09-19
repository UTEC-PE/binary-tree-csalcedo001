#ifndef NODE
#define NODE

template <typename T>
struct Node {
    int data;

    Node *left;
    Node *right;

    void killSelf() {
        if (left)
            left->killSelf();

        if (right)
            right->killSelf();

        delete this;
    }

    Node () {
        left = right = nullptr;
    }
    Node (int data) : data(data) {
        left = right = nullptr;
    }
};

#endif
