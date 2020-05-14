#include "AVLTree.h"

AVLTree::AVLTree() : BinaryTree() {

}

AVLTree::AVLTree(const std::string &word) : BinaryTree(word) {

}

int AVLTree::getDepth(BTNode *node) {
    if (node == nullptr)
        return 0;
    int i = getDepth(node->getLeft());
    int j = getDepth(node->getRight());
    int max = i > j ? i : j;
    node->setHeight(max);
    return max + 1;

}
int AVLTree::height(BTNode* node){
    if(!node)
        return -1;
    return node->getHeight();
}

void AVLTree::fixHeight(BTNode *node) {
    if(!node)
        return;
    int i = height(node->getLeft());
    int j = height(node->getRight());
    i = i>j?i:j;
    if(node->getHeight()==i+1)
        return;
    else {
        node->setHeight(i + 1);
        fixHeight(node->getParent());
    }

}

BTNode *AVLTree::add(const std::string &key) {
    BTNode *node = BinaryTree::add(key);
    fixHeight(node->getParent());
    return node;
}