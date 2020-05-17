#ifndef DATASTRUCTURES_AVLTREE_H
#define DATASTRUCTURES_AVLTREE_H

#include "BinaryTree.h"
#include "BTNode.h"

class AVLTree : public BinaryTree {
public:
    AVLTree();

    explicit AVLTree(const std::string &);

    BTNode *insert(const std::string &key) override;

    BTNode *remove(const std::string &key) override;

    int getDepth(BTNode *node);

    void balance(BTNode *node);

    static int height(BTNode *node);

    bool rotate(BTNode *node, int diff = 10);

    void rotateRight(BTNode *node);

    void rotateLeft(BTNode *node);

    static int heightDiff(BTNode *node);

    static bool fixHeight(BTNode *node, int diff);
};


#endif //DATASTRUCTURES_AVLTREE_H
