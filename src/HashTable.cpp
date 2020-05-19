#include <iostream>
#include <random>
#include "HashTable.h"

typedef std::hash<std::string> hash;

HashTable::HashTable(int cap) {
    capacity = cap;
    size = 0;
    collisions = 0;
    table = new std::string[capacity];
    count = new int[capacity];
}

unsigned int HashTable::h1(unsigned int key) const {
    return key % capacity;
}

unsigned int HashTable::h2(unsigned int key) const {
    return (33 - (key % 33));
}

unsigned int HashTable::h(unsigned int key, unsigned int i) {
    std::mt19937 generator(key);
    static std::uniform_int_distribution<unsigned int> distribution;
    auto rand = distribution(generator);
    return (key + i * rand) % capacity;
}


void HashTable::insert(std::string &str) {
    unsigned int k = hash{}(str);
    int i = 0;
    std::size_t j = h(k, i);
    while (!table[j].empty()) {
        if (table[j] == str) {
            count[j]++;
            return;
        }
        collisions++;
        i++;
        j = h(k, i);
    }
    table[j] = str;
    count[j] = 1;
    size++;

    if (loadFactor() > 70)
        resize(2 * capacity);
}

void HashTable::resize(int cap) {
    auto *tempTable = new std::string[cap];
    int *tempCount = new int[cap];
    int tempCap = capacity;
    capacity = cap;
    for (int z = 0; z < tempCap; z++) {
        std::string str = table[z];
        int c = count[z];
        if (!str.empty()) {
            unsigned int k = hash{}(str);
            int i = 0;
            unsigned int j = h(k, i);
            while (!tempTable[j].empty()) {
                collisions++;
                i++;
                j = h(k, i);
            }
            tempTable[j] = str;
            tempCount[j] = c;
        }
    }
    delete[] table;
    delete[] count;
    table = tempTable;
    count = tempCount;
}

int HashTable::contains(const std::string &str) {
    int k = hash{}(str);
    int i = 0;
    unsigned int j = h(k, i);
    while (!table[j].empty()) {
        if (table[j] == str)
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
