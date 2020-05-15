#include <iostream>
#include <vector>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "Reader.h"

using namespace std;

int main() {
    AVLTree tree;
    int op = 1;
    string table[9] = {"F", "B", "H", "A", "C", "G", "L", "M", "O"};
    switch (op) {
        case 1: {
            for (auto &i : table) {
                cout << "insert " << i << endl;
                tree.insert(i);
                tree.preOrder(tree.getRoot());
            }
            tree.remove("A");
            tree.remove("C");
            cout << "remove A, C" << endl;
            tree.preOrder(tree.getRoot());
            break;
        }
        case 2: {
            cout << "step 1" << endl;
            Reader reader("Dracula.txt");
            cout << "step 2" << endl;
            reader.cleanFile();
            cout << "step 3" << endl;
            reader.buildAVLTree(tree);
            cout << "step 4" << endl;
            tree.preOrder(tree.getRoot());
            cout << "step 5" << endl;
            break;
        }
    }
    return 0;
}
