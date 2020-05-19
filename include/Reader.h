#ifndef DATASTRUCTURES_READER_H
#define DATASTRUCTURES_READER_H

#include <fstream>
#include <AVLTree.h>

class Reader {
private:
    std::ifstream file;
    std::string fileName;

    static void cleanWord(std::string &);

public:
    explicit Reader(const std::string &);

    void cleanFile();

    template<class T>
    void build(T &ds);

    const std::string &getFileName() const;

    int bulkSearch(const BinaryTree &tree);

    void setFileName(const std::string &fileName);

    int wordCount();

};

template<class T>
void Reader::build(T &ds) {
    if (!file.is_open())
        return;
    std::string word;
    while (file >> word) {
        ds.insert(word);
    }
    file.clear();
    file.seekg(0, std::ios::beg);
}


#endif //DATASTRUCTURES_READER_H
