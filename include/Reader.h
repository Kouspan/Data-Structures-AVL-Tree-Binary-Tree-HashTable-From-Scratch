#ifndef DATASTRUCTURES_READER_H
#define DATASTRUCTURES_READER_H
#include <fstream>
#include <AVLTree.h>

class Reader {
private:
    std::ifstream file;
    std::string fileName;
public:
    explicit Reader(const std::string& );
    void cleanFile();
    void buildAVLTree(AVLTree&);
    const std::string &getFileName() const;
    static void cleanWord(std::string&);
    void setFileName(const std::string &fileName);
};


#endif //DATASTRUCTURES_READER_H
