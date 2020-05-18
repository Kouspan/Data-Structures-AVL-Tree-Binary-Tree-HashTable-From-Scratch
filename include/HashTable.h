#ifndef DATASTRUCTURES_HASHTABLE_H
#define DATASTRUCTURES_HASHTABLE_H


#include <string>

class HashTable {
private:
    int capacity;
    int size;
    std::string *table;
    int count[];

    int h1(int k);

    int h2(int k);

    int h(int k, int i);

    int hash(const std::string &str);

    void resize(int M);


public:
    HashTable();

    HashTable(int M);

    void insert(std::string str);

    int contains(std::string str);


};

#endif //DATASTRUCTURES_HASHTABLE_H
