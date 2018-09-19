#ifndef BTREE
#define BTREE

#include "node.h"

template <typename T>
class BinaryTree {
    private:
        Node <T> *head;
        int nodes;

    public:
        BinaryTree() : head(nullptr), nodes(0) {};

        void insert(T data) {
            if (!head) {
                head = new Node <T> (data);
                nodes++;
                return;
            }

            Node <T> **tmp = &head;

            while (*tmp != nullptr)
                if (data < (*tmp)->data)
                    tmp = &((*tmp)->left);
                else if (data > tmp->data)
                    tmp = &((*tmp)->right);
                else
                    return;

            *tmp = new Node <T>(data);
            nodes++;
        }
        void remove(int position) {
            //TODO
        };
        bool empty() {
            return !head;
        }

        ~BinaryTree() {
            head->killSelf();
        }
};

#endif
