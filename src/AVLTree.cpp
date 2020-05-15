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

/** calculates all the heights of @param node and it's descendants **/
int AVLTree::getDepth(BTNode *node) {
    if (node == nullptr)
        return 0;
    int i = getDepth(node->getLeft());
    int j = getDepth(node->getRight());
    int max = i > j ? i : j;
    node->setHeight(max);
    return max + 1;

}

/**height of node **/
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
        balance(node);                      //balance node after rotation
    else {                                   //else check if node height is correct
        int max = diff < 0 ? height(node->getRight()) : height(node->getLeft());//max height of children
        if (node->getHeight() == max + 1)   //if it is, then return. tree is balanced
            return;
        node->setHeight(max + 1);     //if not, change height of node and balance it's parent.
        balance(node->getParent());
    }
}

bool AVLTree::rotate(BTNode *node, int diff) {

    switch (diff) {
        case -2: {
            int childDiff = heightDiff(node->getRight());
            if (childDiff < 0)
                rotateLeft(node);
            else
                rotateRightLeft(node);
            break;
        }
        case 2: {
            int childDiff = heightDiff(node->getLeft());
            if (childDiff > 0)
                rotateRight(node);
            else
                rotateLeftRight(node);
            break;
        }
        case 10:
            rotate(node, heightDiff(node));
        default:
            return false;
    }
    return true;
}

/**height difference of node->left and node->right **/
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

void AVLTree::rotateRightLeft(BTNode *node) {

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

void AVLTree::rotateLeftRight(BTNode *node) {

}