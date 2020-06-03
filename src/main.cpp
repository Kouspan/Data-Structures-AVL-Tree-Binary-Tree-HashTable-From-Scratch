#include <iostream>
#include <chrono>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "Reader.h"
#include "HashTable.h"

using namespace std;

int main() {
    ofstream out("output.txt", ios::trunc); //delete previous contents of file
    out.close();
    out.open("output.txt", ios::app);
    out << "RESULTS BELOW OF EACH SET OF WORDS\n" << endl;

    BinaryTree Btree;
    AVLTree tree;
    HashTable ht(20639);
    Reader book("Dracula.txt");
    book.cleanFile();
    Reader snip("Dracula_snip.txt");
    snip.cleanFile();
    int s_w = snip.wordCount();
    //Binary Tree output
    auto now = chrono::steady_clock::now();
    book.build(Btree);
    auto mid = chrono::steady_clock::now();
    int found = snip.bulkSearch(Btree);
    auto end = chrono::steady_clock::now();
    out << "\nBinary Tree: { \n\t" << "total words: " << Btree.count(Btree.getRoot()) << endl;
    out << "\tunique words: " << Btree.uniqueCount(Btree.getRoot()) << endl;
    out << "\tbuild time: " << chrono::duration_cast<chrono::milliseconds>(mid - now).count() << " ms" << endl;
    out << "\tsearched words: " << s_w << ".\tfound: " << found << endl;
    out << "\tsearch time: " << chrono::duration_cast<chrono::milliseconds>(end - mid).count() << " ms\n}" << endl;
    //AVL Tree output
    now = chrono::steady_clock::now();
    book.build(tree);
    mid = chrono::steady_clock::now();
    found = snip.bulkSearch(tree);
    end = chrono::steady_clock::now();
    out << "\nAVL Tree: { \n\t" << "total words: " << Btree.count(tree.getRoot()) << endl;
    out << "\tunique words: " << Btree.uniqueCount(tree.getRoot()) << endl;
    out << "\tbuild time: " << chrono::duration_cast<chrono::milliseconds>(mid - now).count() << " ms" << endl;
    out << "\tsearched words: " << s_w << ".\tfound: " << found << endl;
    out << "\tsearch time: " << chrono::duration_cast<chrono::milliseconds>(end - mid).count() << " ms\n}" << endl;
    //HashTable output
    now = chrono::steady_clock::now();
    book.build(ht);
    mid = chrono::steady_clock::now();
    found = snip.bulkContains(ht);
    end = chrono::steady_clock::now();
    out << "\nHashTable: { \n\t" << "filled %: " << ht.loadFactor() << "%" << endl;
    out << "\tunique words: " << ht.getSize() << endl;
    out << "\tbuild time: " << chrono::duration_cast<chrono::milliseconds>(mid - now).count() << " ms" << endl;
    out << "\tsearched words: " << s_w << ".\tfound: " << found << endl;
    out << "\tsearch time: " << chrono::duration_cast<chrono::milliseconds>(end - mid).count() << " ms\n}" << endl;

    return 0;
}
