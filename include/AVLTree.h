#ifndef DATASTRUCTURES_AVLTREE_H
#define DATASTRUCTURES_AVLTREE_H

#include "BinaryTree.h"
#include "BTNode.h"

class AVLTree : public BinaryTree {
private:
    static int height(BTNode *node);

    /**
     * Checks if node needs to rotate and if it's height is correct
     * If node rotated or it's height is not correct, it calls itself
     * recursively with parent of node.
     */
    void balance(BTNode *node);

    /**
     * Chooses the correct rotation based on the difference of the height
     * of node's children and their children.
     * @param node
     * @param diff difference of node's children
     * @return true if node rotated
     */
    bool rotate(BTNode *node, int diff);

    void rotateRight(BTNode *node);

    void rotateLeft(BTNode *node);

    /**
     * height difference of node->left and node->right
     * @param node
     * @return left->height - right->height
     */
    static int heightDiff(BTNode *node);

    /**
     * Checks if the height of node is correct bases on it's children.
     * If its not, change it.
     * @param node
     * @param diff @see heightDiff(BTNode *node)
     * @return true if the height was changed
     */
    static bool fixHeight(BTNode *node, int diff);

public:
    AVLTree();

    explicit AVLTree(const std::string &);

    BTNode *insert(const std::string &key) override;

    BTNode *remove(const std::string &key) override;


};


#endif //DATASTRUCTURES_AVLTREE_H
