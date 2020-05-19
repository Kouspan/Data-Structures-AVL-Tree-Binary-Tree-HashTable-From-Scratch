#include <iostream>
#include <chrono>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "Reader.h"
#include "HashTable.h"
using namespace std;

int main() {
    BinaryTree Btree;
    AVLTree tree;
    HashTable ht(18037);
    int op = 4;
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
            reader.build(tree);
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
            reader.build(Btree);
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
        case 4: {
            auto now = chrono::steady_clock::now();
            Reader reader("clean_Dracula_snip.txt");
            reader.build(ht);
            auto end = chrono::steady_clock::now();
            auto time_span = chrono::duration_cast<chrono::milliseconds>(end - now);
            cout << "time: " << time_span.count() << " milliseconds" << endl;
            cout << "unique words " << ht.getSize() << endl;
            cout << "collisions " << ht.getCollisions() << endl;
            now = chrono::steady_clock::now();
            cout << ht.contains("till") << endl;
            end = chrono::steady_clock::now();
            cout << "time :" << chrono::duration_cast<chrono::nanoseconds>(end - now).count();
        }
    }
    return 0;
}
