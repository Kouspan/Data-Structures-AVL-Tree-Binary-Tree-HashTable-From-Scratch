#include "AVLTree.h"

AVLTree::AVLTree() : BinaryTree() {

}

AVLTree::AVLTree(const std::string &word) : BinaryTree(word) {

}

BTNode *AVLTree::insert(const std::string &key) {
    BTNode *node = BinaryTree::insert(key);
    balance(node->getParent());
    return node;
}

BTNode *AVLTree::remove(const std::string &key) {
    BTNode *node = BinaryTree::remove(key);
    balance(node);
    return node;
}

int AVLTree::height(BTNode *node) {
    if (!node)
        return -1;
    return node->getHeight();
}

/**adjust height of node and it's ancestors, rotates node if needed **/
void AVLTree::balance(BTNode *node) {
    if (!node)
        return;
    int diff = heightDiff(node);
    if (rotate(node, diff))                 //if node rotated
        diff = heightDiff(node);            //fix it's height node after rotation
    if (fixHeight(node, diff))
        balance(node->getParent());
}

bool AVLTree::rotate(BTNode *node, int diff) {

    switch (diff) {
        case -2: {
            BTNode *child = node->getRight();
            int childDiff = heightDiff(node->getRight());
            if (childDiff < 0)
                rotateLeft(node);
            else {
                rotateRight(child);
                rotateLeft(node);
                fixHeight(child, heightDiff(child));
            }
            break;
        }
        case 2: {
            BTNode *child = node->getLeft();
            int childDiff = heightDiff(child);
            if (childDiff > 0)
                rotateRight(node);
            else {
                rotateLeft(node->getLeft());
                rotateRight(node);
                fixHeight(child, heightDiff(child));
            }
            break;
        }
        default:
            return false;
    }
    return true;
}

/** **/
int AVLTree::heightDiff(BTNode *node) {
    return height(node->getLeft()) - height(node->getRight());
}

void AVLTree::rotateLeft(BTNode *node) {
    BTNode *child = node->getRight();
    if (node->getParent()) {
        if (node->getParent()->getRight() == node)
            node->getParent()->setRight(child);
        else
            node->getParent()->setLeft(child);
    } else
        this->setRoot(child);
    node->setRight(child->getLeft());
    child->setLeft(node);
}

void AVLTree::rotateRight(BTNode *node) {
    BTNode *child = node->getLeft();
    if (node->getParent()) {
        if (node->getParent()->getRight() == node)
            node->getParent()->setRight(child);
        else
            node->getParent()->setLeft(child);
    } else
        this->setRoot(child);
    node->setLeft(child->getRight());
    child->setRight(node);

}

bool AVLTree::fixHeight(BTNode *node, int diff) {
    int max = diff < 0 ? height(node->getRight()) : height(node->getLeft());
    if (node->getHeight() == max + 1)   //if it is, then return. tree is balanced
        return false;
    node->setHeight(max + 1);
    return true;
}