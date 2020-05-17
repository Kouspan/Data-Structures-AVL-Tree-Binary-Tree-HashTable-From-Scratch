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

    void buildTree(BinaryTree &tree);

    const std::string &getFileName() const;

    int bulkSearch(const BinaryTree &tree);

    void setFileName(const std::string &fileName);

    int wordCount();

};


#endif //DATASTRUCTURES_READER_H
