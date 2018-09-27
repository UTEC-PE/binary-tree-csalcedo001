#include <iostream>
#include <stack>

#include "btree.h"

using namespace std;

int main (void) {
    BinaryTree <int> tree;

    cout << endl << "Insert nodes" << endl;
    tree.insert(3);
    tree.insert(1);
    tree.insert(0);
    tree.insert(2);
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);


    cout << endl << "Print structure" << endl;

    tree.print();


    cout << endl << "Supports double insertions" << endl;

    for (int i = 0; i < 7; i++)
        tree.insert(i);

    tree.print();




    cout << endl << "Iterate through the tree" << endl;

    for (BinaryTree <int>::iterator it = tree.begin(); it != tree.end(); ++it)
        cout << *it * *it<< " ";

    cout << endl;


    cout << endl << "Calculate height" << endl;
    cout << tree.height() << endl;

    cout << endl << "Calculate weight" << endl;
    cout << tree.weight() << endl;



    cout << endl << "Remove nodes" << endl;

    tree.remove(0);
    tree.print();

    tree.remove(1);
    tree.print();

    tree.remove(5);
    tree.print();



    cout << endl << "Elements not present in the tree aren't removed" << endl << endl;

    tree.remove(7);
    tree.print();



    cout << "Continue removing..." << endl;
    tree.remove(3);
    tree.print();

    tree.remove(2);
    tree.print();

    tree.remove(4);
    tree.print();

    tree.remove(6);
    tree.print();

    return 0;
}
