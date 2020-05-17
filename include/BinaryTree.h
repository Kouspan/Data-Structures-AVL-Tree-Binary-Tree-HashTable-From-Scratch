#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <BTNode.h>

class BinaryTree {
private:
    BTNode *root;

    void deleteTree(BTNode *node);

public:
    BinaryTree();

    ~BinaryTree();

    explicit BinaryTree(const std::string &);

    BTNode *getRoot();

    void setRoot(BTNode *node);

    virtual BTNode *insert(const std::string &);

    virtual BTNode *remove(const std::string &);

    BTNode *search(const std::string &) const;

    void postOrder(BTNode *node);

    void inOrder(BTNode *node);

    void preOrder(BTNode *node);

    int count(BTNode *node);

    int uniqueCount(BTNode *node);


};

#endif //BINARY_TREE_H