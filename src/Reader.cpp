#include "Reader.h"
#include <sstream>
#include <string>
#include <iostream>

Reader::Reader(const std::string &name) {
    Reader::fileName = name;
    file.open(fileName);
}

void Reader::clean() {
    if (!file.is_open())
        return;
    std::ofstream output;
    std::string name_new = "clean_" + fileName;
    output.open(name_new);
    std::string line;
    std::string word;
    std::stringstream ss;


    while (std::getline(file, line)) {
        std::size_t t = 0;
        while ((t = line.find('-', t + 2)) != std::string::npos) {
            line.replace(t, 1, " ");
        }
        ss.clear();
        ss << line;
        try {
            while (ss.good()) {
                ss>>word;
                auto it_f = word.begin();
                while (ispunct(*it_f))
                    word.erase(it_f);
                for (; isupper(*it_f); it_f++) {
                    *it_f = tolower(*it_f);
                }
                auto it_b = word.end() - 1;//starts left of "\000"
                for (; ispunct(*it_b); it_b--) {
                    word.erase(it_b);
                }
                output << word << " ";
            }
        } catch (...) {
            std::cout<<"catch___";
        }
        output << std::endl;
    }

    setFileName(name_new);
}

const std::string &Reader::getFileName() const {
    return fileName;
}

void Reader::setFileName(const std::string &fileName) {
    Reader::fileName = fileName;
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
