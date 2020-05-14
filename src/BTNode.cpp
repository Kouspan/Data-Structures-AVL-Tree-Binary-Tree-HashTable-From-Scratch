#include <BTNode.h>


BTNode::BTNode() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    copies = 1;
    height = 0;
}

BTNode::BTNode(const std::string &element1) : BTNode() {
    element = element1;
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

std::string BTNode::getElement() const {
    return element;
}

int BTNode::getCopies() const {
    return copies;
}

int BTNode::getHeight() const {
    return height;
}

void BTNode::setParent(BTNode *parent1) {
    parent = parent1;
}

void BTNode::setLeft(BTNode *left1) {
    left = left1;
    if(left)
        left->setParent(this);
}

void BTNode::setRight(BTNode *right1) {
    right = right1;
    if(right)
        right->setParent(this);
}

void BTNode::setElement(const std::string &element1) {
    BTNode::element = element1;
}

void BTNode::setCopies(int a) {
    copies = a;
}

void BTNode::setHeight(int height) {
    BTNode::height = height;
}

BTNode &BTNode::operator=(const BTNode &node) {
    if (this == &node)
        return *this;
    element = node.getElement();
    parent = node.getParent();
    left = node.getLeft();
    right = node.getRight();
    copies = node.getCopies();
    return *this;
}

void BTNode::incHeight() {
    height++;

}







