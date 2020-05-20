#ifndef DATASTRUCTURES_HASHTABLE_H
#define DATASTRUCTURES_HASHTABLE_H


#include <string>
/**
 * Open address hash table with a string array for words and
 * an int array for the copies of words
 */
class HashTable {
private:
    std::string *table;
    int *count;
    int capacity;
    int size;
    int collisions;

    /**
     * Quadratic probing function
     * @param key word hashed with std::hash<std::string>
     * @param i number of collisions
     * @return position in table
     */
    unsigned int h(unsigned int key, unsigned int i) const;

    /**
     * Creates new string and int tables of size m and re-inserts the
     * elements of the current hash table.
     * @param m size of the new table.
     */
    void resize(int m);


public:
    int getCapacity() const;

    int getCollisions() const;

    int getSize() const;

    explicit HashTable(int cap);

    /**
     * Inserts a word in the hash table.
     * If the word already exists, it increments it's copies by 1
     * @param word
     */
    void insert(std::string &word);

    /**
     * Searches if a word exists in the hash table.
     * @param word string to search.
     * @return number of copies of word, if word exists, else 0.
     */
    int contains(const std::string &word) const;

    /**
     *
     * @return percentage of occupied space in table.
     */
    double loadFactor() const;


};

#endif //DATASTRUCTURES_HASHTABLE_H
