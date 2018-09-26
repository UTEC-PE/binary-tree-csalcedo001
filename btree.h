#ifndef BTREE
#define BTREE

#include <iostream>

#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class BinaryTree {
    private:
        Node <T> *head;
        int nodes;

    public:
        BinaryTree() : nodes(0) {
            head = new Node <T>;

            head->left = head->right = nullptr;
        };

        void insert(T data) {
            if (!head->right) {
                head->left = head->right = new Node <T> (data);
                nodes++;

                return;
            }

            Node <T> **tmp = &(head->right);

            while (*tmp != nullptr)
                if (data < (*tmp)->data)
                    tmp = &((*tmp)->left);
                else if (data > (*tmp)->data)
                    tmp = &((*tmp)->right);
                else
                    return;

            *tmp = new Node <T>(data);

            nodes++;
        }
        // TODO: BinaryTree::remove should rearrange the original tree
        // void remove(T data) {
        //     if (!head)
        //         return;
        //
        //     Node <T> **tmp = &head;
        //
        //     while (*tmp != nullptr)
        //         if (data < (*tmp)->data)
        //             tmp = &((*tmp)->left);
        //         else if (data > (*tmp)->data)
        //             tmp = &((*tmp)->right);
        //         else {
        //             delete *tmp;
        //             *tmp = nullptr;
        //
        //             nodes--;
        //
        //             return;
        //         }
        // }
        void print() {
            if (head->right)
                head->right->print();

            cout << endl;
        }
        int length() {
            return nodes;
        }
        int weight() {
            return nodes;
        }
        //TODO: int height() {};
        bool empty() {
            return !head->right;
        }
        void clear() {
            if (head->right)
                head->right->killSelf();
        }
        Iterator <T> begin() {
            stack <Node <T> *> tmp_stack;
            Node <T> *tmp = head;

            while (tmp->left) {
                tmp_stack.push(tmp);
                tmp = tmp->left;
            }

            return Iterator <T> (tmp, tmp_stack);
        }
        Iterator <T> end() {
            stack <Node <T> *> tmp_stack;

            return Iterator <T> (head, tmp_stack);
        }

        ~BinaryTree() {
            clear();

            delete head;
        }
};

#endif
