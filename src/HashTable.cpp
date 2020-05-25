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

int HashTable::insert(std::string &word) {
    unsigned int k = hash{}(word);
    unsigned int i = 0;
    std::size_t j = h(k, i);
    while (!table[j].empty()) {
        if (table[j] == word) {
            count[j]++;
            return j;
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
    return j;
}

void HashTable::resize(int cap) {
    std::string *tempTable = table;
    int *tempCount = count;
    int tempCap = capacity;
    capacity = cap;
    table = new std::string[cap];
    count = new int[cap];
    for (int i = 0; i < tempCap; i++) {
        std::string word = tempTable[i];
        int c = tempCount[i];
        if (!word.empty()) {
            int j = insert(word);
            count[j] = c;
        }
    }
    delete[] tempTable;
    delete[] tempCount;
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

HashTable::~HashTable() {
    delete[] table;
    delete[] count;
}