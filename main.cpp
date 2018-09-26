#include <iostream>
#include <stack>

#include "btree.h"

using namespace std;

int main (void) {
    BinaryTree <int> tree;

    tree.insert(2);
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(2);

    tree.print();

    for (Iterator <int> it = tree.begin(); it != tree.end(); ++it)
        cout << *it << " ";

    cout << endl;

    return 0;
}
