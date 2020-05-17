#include <iostream>
#include <chrono>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "Reader.h"

using namespace std;

int main() {
    BinaryTree Btree;
    AVLTree tree;
    int op = 2;
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
            auto now = chrono::steady_clock::now();
            Reader reader("clean_Dracula.txt");
            reader.buildTree(tree);
            auto end = chrono::steady_clock::now();
            auto time_span = chrono::duration_cast<chrono::milliseconds>(end - now);
            cout << "time: " << time_span.count() << " milliseconds" << endl;
            cout << tree.count(tree.getRoot()) << " " << tree.uniqueCount(tree.getRoot()) << endl;
            Reader reader1("clean_dracula_snip.txt");
            cout << "searching..." << reader1.wordCount() << " words" << endl;
            auto now2 = chrono::steady_clock::now();
            cout << "found :" << reader1.bulkSearch(tree) << endl;
            auto end2 = chrono::steady_clock::now();
            cout << "time: " << chrono::duration_cast<chrono::milliseconds>(end2 - now2).count() << endl;
            break;
        }
        case 3: {
            auto now = chrono::steady_clock::now();
            Reader reader("clean_Dracula.txt");
            reader.buildTree(Btree);
            auto end = chrono::steady_clock::now();
            auto time_span = chrono::duration_cast<chrono::milliseconds>(end - now);
            cout << "time: " << time_span.count() << " milliseconds" << endl;
            cout << Btree.count(Btree.getRoot()) << " " << Btree.uniqueCount(Btree.getRoot()) << endl;
            Reader reader1("clean_dracula_snip.txt");
            cout << "searching..." << reader.wordCount() << " words" << endl;
            auto now2 = chrono::steady_clock::now();
            cout << "found :" << reader.bulkSearch(Btree) << endl;
            auto end2 = chrono::steady_clock::now();
            cout << "time: " << chrono::duration_cast<chrono::milliseconds>(end2 - now2).count() << endl;
            break;
        }
    }
    return 0;
}
