#include "BinaryTree.h"
#include <BTNode.h>
#include <iostream>

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    deleteTree(root);
}

BinaryTree::BinaryTree(const std::string &root) {
    BinaryTree::root = new BTNode(root);
}

void BinaryTree::deleteTree(BTNode *node) {
    if (node == nullptr)
        return;
    deleteTree(node->getLeft());
    deleteTree(node->getRight());
    delete node;
}

BTNode *BinaryTree::getRoot() {
    return root;
}

void BinaryTree::setRoot(BTNode *node) {
    root = node;
    root->setParent(nullptr);
}


BTNode *BinaryTree::insert(const std::string &word) {
    if (root == nullptr) {
        root = new BTNode(word);
        return root;
    }
    BTNode *p = root;
    BTNode *pp = root->getParent();
    while (p != nullptr) {
        pp = p;
        if (word < p->getElement())
            p = p->getLeft();
        else if (word > p->getElement())
            p = p->getRight();
        else {
            p->setDuplicates(p->getDuplicates() + 1);
            return p;
        }
    }
    auto *node = new BTNode(word);
    if (word < pp->getElement())
        pp->setLeft(node);
    else
        pp->setRight(node);
    return node;
}


BTNode *BinaryTree::remove(const std::string &key) {
    BTNode *node = search(key);
    if (node == nullptr)
        return node;
    if (node->getDuplicates() > 1)//if more than 1 duplicates, decrement by 1.
        node->setDuplicates(node->getDuplicates() - 1);
    else {
        //find largest value of left subtree
        if (node->getRight() != nullptr && node->getLeft() != nullptr) {
            BTNode *p = node->getLeft();
            while (p->getRight() != nullptr) {
                p = p->getRight();
            }
            node->setElement(p->getElement());
            node->setDuplicates(p->getDuplicates());
            node = p;
        }
        //find if node has child
        BTNode *c = nullptr;
        if (node->getLeft() != nullptr)
            c = node->getLeft();
        if (node->getRight() != nullptr)
            c = node->getRight();
        //replace node with child before deleting it
        if (node == root)
            root = c;
        else if (node == node->getParent()->getLeft())
            node->getParent()->setLeft(c);
        else
            node->getParent()->setRight(c);
    }
    BTNode *parent = node->getParent();
    delete node;
    return parent;
}


BTNode *BinaryTree::search(const std::string &key) const {
    BTNode *p = root;
    while (p != nullptr) {
        if (key < p->getElement())
            p = p->getLeft();
        else if (key > p->getElement())
            p = p->getRight();
        else {
            return p;
        }
    }
    return p;

}

void BinaryTree::postOrder(BTNode *node) {
    if (node == nullptr)
        return;
    postOrder(node->getLeft());
    postOrder(node->getRight());
    std::cout << node->getElement() << " " << node->getDuplicates() << std::endl;
}

void BinaryTree::inOrder(BTNode *node) {
    if (node == nullptr)
        return;
    inOrder(node->getLeft());
    std::cout << node->getElement() << " " << node->getDuplicates() << std::endl;
    inOrder(node->getRight());
}

void BinaryTree::preOrder(BTNode *node) {
    if (node == nullptr)
        return;
    std::cout << node->getElement() << " " << node->getDuplicates() << std::endl;
    preOrder(node->getLeft());
    preOrder(node->getRight());
}

int BinaryTree::count(BTNode *node) {
    if (!node)
        return 0;
    return node->getDuplicates() + count(node->getLeft()) + count(node->getRight());
}

int BinaryTree::uniqueCount(BTNode *node) {
    if (!node)
        return 0;
    return 1 + uniqueCount(node->getLeft()) + uniqueCount(node->getRight());
}



