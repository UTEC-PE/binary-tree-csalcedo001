#ifndef BTREE
#define BTREE

#include <iostream>

#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class BinaryTree {
    public:
        typedef Iterator <T> iterator;
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
        void remove(T data) {
            if (!head->right)
                return;


            if (!head->right->left && !head->right->right && head->right->data == data) {
                delete head->right;

                head->left = head->right = nullptr;

                return;
            }

            Node <T> **tmp = &(head->right);

            while (*tmp != nullptr && (*tmp)->data != data)
                if (data < (*tmp)->data)
                    tmp = &((*tmp)->left);
                else if (data > (*tmp)->data)
                    tmp = &((*tmp)->right);

            // No match with data
            if (!*tmp)
                return;

            Node <T> *to_delete = *tmp;

            // Node has two childs
            if (to_delete->left && to_delete->right) {
                Node <T> *to_update = to_delete;

                tmp = &((*tmp)->left);

                while ((*tmp)->right)
                    tmp = &((*tmp)->right);

                to_delete = *tmp;

                to_update->data = to_delete->data;
            }

            // Node has one child
            if (to_delete->left || to_delete->right)
                *tmp = to_delete->right ? to_delete->right : to_delete->left;
            else
                *tmp = nullptr; // Node has no childs

            // Update root left node
            if (tmp == &head->right)
                head->left = *tmp;

            delete to_delete;

            nodes--;
        }
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
        int height() {
            return head->right ? head->right->height() : 0;
        };
        bool empty() {
            return !head->right;
        }
        void clear() {
            if (head->right)
                head->right->killSelf();

            head->right = head->left = nullptr;

            nodes = 0;
        }
        iterator begin() {
            stack <Node <T> *> tmp_stack;
            Node <T> *tmp = head;

            while (tmp->left) {
                tmp_stack.push(tmp);
                tmp = tmp->left;
            }

            return iterator(tmp, tmp_stack);
        }
        iterator end() {
            stack <Node <T> *> tmp_stack;

            return iterator(head, tmp_stack);
        }

        ~BinaryTree() {
            clear();

            delete head;
        }
};

#endif
