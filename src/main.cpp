#include <iostream>
#include <chrono>
#include <sstream>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "Reader.h"
#include "HashTable.h"

using namespace std;

int main() {

    ofstream out("output.txt", ios::trunc); //delete previous contents of file
    out.close();
    out.open("output.txt", ios::app);
    out << "TIME RESULTS AT THE END OF FILE\n" << endl;
    stringstream temp{};
    BinaryTree Btree;
    AVLTree tree;
    HashTable ht(20639);
    Reader book("Dracula.txt");
    book.cleanFile();
    Reader snip("Dracula_snip.txt");
    snip.cleanFile();
    int s_w = snip.wordCount();

    //Binary Tree output
    out << "------RESULTS OF BINARY TREE SEARCH------" << endl;
    auto now = chrono::steady_clock::now();
    book.build(Btree);
    auto mid = chrono::steady_clock::now();
    int found = snip.bulkSearch(Btree);
    auto end = chrono::steady_clock::now();
    out << "------END OF BINARY TREE SEARCH------\n" << endl;
    temp << "\nBinary Tree: { \n\t" << "total words: " << Btree.count(Btree.getRoot()) << endl;
    temp << "\tunique words: " << Btree.uniqueCount(Btree.getRoot()) << endl;
    temp << "\tbuild time: " << chrono::duration_cast<chrono::milliseconds>(mid - now).count() << " ms" << endl;
    temp << "\tsearched words: " << s_w << ".\tfound: " << found << endl;
    temp << "\tsearch time: " << chrono::duration_cast<chrono::milliseconds>(end - mid).count() << " ms\n}" << endl;

    //AVL Tree output
    out << "------RESULTS OF AVL TREE SEARCH------" << endl;
    now = chrono::steady_clock::now();
    book.build(tree);
    mid = chrono::steady_clock::now();
    found = snip.bulkSearch(tree);
    end = chrono::steady_clock::now();
    out << "------END OF AVL TREE SEARCH------\n" << endl;
    temp << "\nAVL Tree: { \n\t" << "total words: " << tree.count(tree.getRoot()) << endl;
    temp << "\tunique words: " << tree.uniqueCount(tree.getRoot()) << endl;
    temp << "\tbuild time: " << chrono::duration_cast<chrono::milliseconds>(mid - now).count() << " ms" << endl;
    temp << "\tsearched words: " << s_w << ".\tfound: " << found << endl;
    temp << "\tsearch time: " << chrono::duration_cast<chrono::milliseconds>(end - mid).count() << " ms\n}" << endl;

    //HashTable output
    out << "------RESULTS OF HASHTABLE SEARCH------" << endl;
    now = chrono::steady_clock::now();
    book.build(ht);
    mid = chrono::steady_clock::now();
    found = snip.bulkContains(ht);
    end = chrono::steady_clock::now();
    out << "------END OF HASHTABLE SEARCH------\n" << endl;
    temp << "\nHashTable: { \n\t" << "filled %: " << ht.loadFactor() << "%" << endl;
    temp << "\tunique words: " << ht.getSize() << endl;
    temp << "\tbuild time: " << chrono::duration_cast<chrono::milliseconds>(mid - now).count() << " ms" << endl;
    temp << "\tsearched words: " << s_w << ".\tfound: " << found << endl;
    temp << "\tsearch time: " << chrono::duration_cast<chrono::milliseconds>(end - mid).count() << " ms\n}" << endl;
    out << "------TIME RESULTS------\n" << endl;
    out << temp.str();

    return 0;
}
