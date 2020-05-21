#include <BTNode.h>


BTNode::BTNode() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    duplicates = 1;
    height = 0;
}

BTNode::BTNode(const std::string &element1) : BTNode() {
    element = element1;
}

std::string BTNode::getElement() const {
    return element;
}

BTNode *BTNode::getParent() const {
    return parent;
}

BTNode *BTNode::getLeft() const {
    return left;
}

BTNode *BTNode::getRight() const {
    return right;
}

int BTNode::getDuplicates() const {
    return duplicates;
}

int BTNode::getHeight() const {
    return height;
}

void BTNode::setElement(const std::string &element1) {
    BTNode::element = element1;
}

void BTNode::setParent(BTNode *parent1) {
    parent = parent1;
}

void BTNode::setLeft(BTNode *left1) {
    left = left1;
    if (left)
        left->setParent(this);
}

void BTNode::setRight(BTNode *right1) {
    right = right1;
    if (right)
        right->setParent(this);
}

void BTNode::setDuplicates(int var) {
    duplicates = var;
}

void BTNode::setHeight(int var) {
    BTNode::height = var;
}