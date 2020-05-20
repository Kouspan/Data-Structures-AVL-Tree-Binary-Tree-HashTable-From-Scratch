#include <iostream>
#include "HashTable.h"

typedef std::hash<std::string> hash;

HashTable::HashTable(int cap) {
    capacity = cap;
    size = 0;
    collisions = 0;
    table = new std::string[capacity];
    count = new int[capacity];
}

unsigned int HashTable::h(unsigned int key, unsigned int i) const {
    return (key + i * i) % capacity;
}


void HashTable::insert(std::string &word) {
    unsigned int k = hash{}(word);
    unsigned int i = 0;
    std::size_t j = h(k, i);
    while (!table[j].empty()) {
        if (table[j] == word) {
            count[j]++;
            return;
        }
        collisions++;
        i++;
        j = h(k, i);
    }
    table[j] = word;
    count[j] = 1;
    size++;
    if (loadFactor() > 50) {
        resize(2 * capacity);
        std::cout << "resized to: " << capacity << std::endl;
    }
}

void HashTable::resize(int cap) {
    std::string *tempTable = new std::string[cap];
    int *tempCount = new int[cap];
    int tempCap = capacity;
    capacity = cap;
    for (int z = 0; z < tempCap; z++) {
        std::string word = table[z];
        int c = count[z];
        if (!word.empty()) {
            unsigned int k = hash{}(word);
            unsigned int i = 0;
            unsigned int j = h(k, i);
            while (!tempTable[j].empty()) {
                collisions++;
                i++;
                j = h(k, i);
            }
            tempTable[j] = word;
            tempCount[j] = c;
        }
    }
    delete[] table;
    delete[] count;
    table = tempTable;
    count = tempCount;
}

int HashTable::contains(const std::string &word) const {
    unsigned int k = hash{}(word);
    unsigned int i = 0;
    unsigned int j = h(k, i);
    while (!table[j].empty()) {
        if (table[j] == word)
            return count[j];
        i++;
        j = h(k, i);
    }
    return 0;
}

double HashTable::loadFactor() const {
    return ((100.0 * size) / capacity);
}

int HashTable::getSize() const {
    return size;
}

int HashTable::getCollisions() const {
    return collisions;
}

int HashTable::getCapacity() const {
    return capacity;
}
