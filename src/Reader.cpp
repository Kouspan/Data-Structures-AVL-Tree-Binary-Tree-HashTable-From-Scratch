#include "Reader.h"
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

Reader::Reader(const std::string &name) {
    Reader::fileName = name;
    file.open(fileName);
}
/**read file and remove all punctuation marks, then save the text to
 * a new file.**/
void Reader::cleanFile() {
    if (!file.is_open())
        return;
    std::ofstream output;
    std::string name_new = "clean_" + fileName;
    output.open(name_new);
    std::string line;
    std::vector<std::string> tokens;

    while (std::getline(file, line)) {
        std::size_t t = -2;
        while ((t = line.find('-', t + 2)) != std::string::npos) {
            line.replace(t, 1, " ");
        }
        std::istringstream ss(line);
        std::copy(std::istream_iterator<std::string>{ss},
             std::istream_iterator<std::string>(), std::back_inserter(tokens));
        for(auto & token : tokens){
            cleanWord(token);
            output<<token<<" ";
        }
        tokens.clear();
        output << std::endl;
    }
    setFileName(name_new);
}
/**clean punctuation marks from front and back of @param word**/
void Reader::cleanWord(std::string &word) {
    auto it_f = word.begin();
    while (ispunct(*it_f))
        word.erase(it_f);
    for (; isupper(*it_f); it_f++)
        *it_f = tolower(*it_f);
    auto it_b = word.end() - 1;//starts left of "\000"
    for (; ispunct(*it_b); it_b--)
        word.erase(it_b);
}

const std::string &Reader::getFileName() const {
    return fileName;
}

void Reader::setFileName(const std::string &fileName1) {
    Reader::fileName = fileName1;
    file.close();
    file.open(fileName);
}

void Reader::buildAVLTree(AVLTree &tree) {
    if (!file.is_open())
        return;
    std::string word;
    while (file >> word) {
        tree.add(word);
    }
}
