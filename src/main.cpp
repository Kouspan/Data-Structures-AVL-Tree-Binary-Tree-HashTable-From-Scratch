#include <iostream>
#include <chrono>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "Reader.h"
#include "HashTable.h"

using namespace std;

int main() {
    ofstream out("output.txt", ios::trunc);
    out.close();
    out.open("output.txt", ios::app);
    out << "RESULTS BELOW OF EACH SET OF WORDS\n" << endl;

    BinaryTree Btree;
    AVLTree tree;
    HashTable ht(20639);
    Reader reader("Dracula.txt");
    reader.cleanFile();
    Reader reader2("Dracula_snip.txt");
    reader2.cleanFile();
    int s_w = reader2.wordCount();
    //Binary Tree output
    auto now = chrono::steady_clock::now();
    reader.build(Btree);
    auto mid = chrono::steady_clock::now();
    int found = reader2.bulkSearch(Btree);
    auto end = chrono::steady_clock::now();
    out << "\nBinary Tree: { \n\t" << "total words: " << Btree.count(Btree.getRoot()) << endl;
    out << "\tunique words: " << Btree.uniqueCount(Btree.getRoot()) << endl;
    out << "\tbuild time: " << chrono::duration_cast<chrono::milliseconds>(mid - now).count() << " ms" << endl;
    out << "\tsearched words: " << s_w << ".\tfound: " << found << endl;
    out << "\tsearch time: " << chrono::duration_cast<chrono::milliseconds>(end - mid).count() << " ms\n}" << endl;
    //AVL Tree output
    now = chrono::steady_clock::now();
    reader.build(tree);
    mid = chrono::steady_clock::now();
    found = reader2.bulkSearch(tree);
    end = chrono::steady_clock::now();
    out << "\nAVL Tree: { \n\t" << "total words: " << Btree.count(tree.getRoot()) << endl;
    out << "\tunique words: " << Btree.uniqueCount(tree.getRoot()) << endl;
    out << "\tbuild time: " << chrono::duration_cast<chrono::milliseconds>(mid - now).count() << " ms" << endl;
    out << "\tsearched words: " << s_w << ".\tfound: " << found << endl;
    out << "\tsearch time: " << chrono::duration_cast<chrono::milliseconds>(end - mid).count() << " ms\n}" << endl;
    //HashTable output
    now = chrono::steady_clock::now();
    reader.build(ht);
    mid = chrono::steady_clock::now();
    found = reader2.bulkContains(ht);
    end = chrono::steady_clock::now();
    out << "\nHashTable: { \n\t" << "filled %: " << ht.loadFactor() << "%" << endl;
    out << "\tunique words: " << ht.getSize() << endl;
    out << "\tbuild time: " << chrono::duration_cast<chrono::milliseconds>(mid - now).count() << " ms" << endl;
    out << "\tsearched words: " << s_w << ".\tfound: " << found << endl;
    out << "\tsearch time: " << chrono::duration_cast<chrono::milliseconds>(end - mid).count() << " ms\n}" << endl;

    return 0;
}
