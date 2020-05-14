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

    virtual BTNode *add(const std::string &);

    void postOrder(BTNode *node);

    void inOrder(BTNode *node);

    void preOrder(BTNode *node);

    BTNode* search(const std::string &);

    virtual BTNode* del(const std::string &);


};

#endif //BINARY_TREE_H