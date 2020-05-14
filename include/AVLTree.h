#ifndef DATASTRUCTURES_AVLTREE_H
#define DATASTRUCTURES_AVLTREE_H
#include "BinaryTree.h"
#include "BTNode.h"

class AVLTree: public BinaryTree {
public:
    AVLTree();
    explicit AVLTree(const std::string &);
    BTNode* add(const std::string&) override;
    /*void rotateRight(BTNode* node);
    void rotateLeft(BTNode* node);
    void rotateRightLeft(BTNode* node);
    void rotateLeftRight(BTNode* node);
    int heightDifference(BTNode* node);
    void balanceTree();*/
    int getDepth(BTNode* node);
    void fixHeight(BTNode* node);
    int height(BTNode* node);




};


#endif //DATASTRUCTURES_AVLTREE_H
