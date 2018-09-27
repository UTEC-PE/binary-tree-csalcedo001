#include <stack>
#include "node.h"

using namespace std;

template <typename T>
class Iterator {
    private:
        Node <T> *current;
        stack <Node <T> *> *roots;

    public:
        Iterator() : current(nullptr) {
            this->roots = new stack <Node <T> *> ();
        }
        Iterator(Node <T> *node, stack <Node <T> *> new_roots) : current(node) {
            this->roots = new stack <Node <T> *> (new_roots);
        }

        Iterator <T>& operator=(Iterator <T> node) {
            current = node.current;

            *roots = *node.roots;

            return *this;
        }
        bool operator!=(Iterator <T> node) {
            return current != node.current;
        }
        Iterator <T>& operator++() {
            if (current->right) {
                roots->push(current);
                current = current->right;

                while (current->left) {
                    roots->push(current);
                    current = current->left;
                }
            } else {
                while (!roots->empty() && current == roots->top()->right) {
                    current = roots->top();
                    roots->pop();
                }

                if (!roots->empty()) {
                    current = roots->top();
                    roots->pop();
                }
            }

            return *this;
        };
        Iterator <T>& operator--() {
            if (current->left) {
                roots->push(current);
                current = current->left;

                while (current->right) {
                    roots->push(current);
                    current = current->right;
                }
            } else {
                while (!roots->empty() && current == roots->top()->left) {
                    current = roots->top();
                    roots->pop();
                }

                if (!roots->empty()) {
                    current = roots->top();
                    roots->pop();
                }
            }

            return *this;
        };
        T operator*() {
            return current->data;
        }

        ~Iterator() {
            delete roots;
        }
};
