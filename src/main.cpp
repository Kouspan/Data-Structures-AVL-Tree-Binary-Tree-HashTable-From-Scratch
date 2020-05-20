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

    int op = 4;
    switch (op) {

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
            reader1.bulkSearch(tree);
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
            reader.bulkSearch(Btree);
            auto end2 = chrono::steady_clock::now();
            cout << "time: " << chrono::duration_cast<chrono::milliseconds>(end2 - now2).count() << endl;
            break;
        }
        case 4: {
            HashTable ht(20639);
            auto now = chrono::steady_clock::now();
            Reader reader("clean_Dracula.txt");
            reader.build(ht);
            auto end = chrono::steady_clock::now();
            auto time_span = chrono::duration_cast<chrono::milliseconds>(end - now);
            cout << "time: " << time_span.count() << " milliseconds" << endl;
            cout << "unique words " << ht.getSize() << endl;
            cout << "collisions " << ht.getCollisions() << endl;
            reader.setFileName("clean_Dracula_snip.txt");
            now = chrono::steady_clock::now();
            reader.bulkContains(ht);
            end = chrono::steady_clock::now();
            cout << "time :" << chrono::duration_cast<chrono::nanoseconds>(end - now).count() << endl;
            cout << ht.loadFactor() << " " << ht.getCapacity();
        }
    }
    return 0;
}
