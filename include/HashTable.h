#ifndef DATASTRUCTURES_HASHTABLE_H
#define DATASTRUCTURES_HASHTABLE_H


#include <string>

class HashTable {
private:
    int capacity;
    int size;
    std::string *table;
    int *count;
    int collisions;

private:

    unsigned int h1(unsigned int k) const;

    unsigned int h2(unsigned int key) const;

    unsigned int h(unsigned int key, unsigned int i);

    void resize(int M);


public:
    int getCollisions() const;

    int getSize() const;

    HashTable(int cap);

    void insert(std::string &str);

    int contains(const std::string &str);

    double loadFactor() const;


};

#endif //DATASTRUCTURES_HASHTABLE_H
