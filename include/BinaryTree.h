#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <BTNode.h>

/**
 * A binary tree made of linked BTNode nodes.
 */
class BinaryTree {
private:
    BTNode *root;

    /**
     * Deletes nodes of tree in post order.
     * @param node root of subtree to be deleted.
     */
    void deleteTree(BTNode *node);

protected:
    void setRoot(BTNode *node);

public:

    BinaryTree();

    /**
     * @see deleteTree(BTNode*);
     */
    ~BinaryTree();

    explicit BinaryTree(const std::string &);

    BTNode *getRoot();


    /**
     * Add word to tree.
     * Increment duplicates of BTNode if word already exists.
     *
     * @return BTNode of word
     */
    virtual BTNode *insert(const std::string &word);

    /**
     * Delete word from tree.
     * If BTNode has more than 1 duplicates of word, decrement by 1.
     *
     * @return BTNode parent of @param word
     */
    virtual BTNode *remove(const std::string &word);

    /**
     * Search word in tree.
     * @return BTNode of word if found, else nullptr.
     */
    BTNode *search(const std::string &word) const;

    void postOrder(BTNode *node);

    void inOrder(BTNode *node);

    void preOrder(BTNode *node);

    /**
     * Count all words in the subtree with root node.
     * @return number of words
     */
    int count(BTNode *node);

    /**
     * Count all unique words in the subtree with root node.
     *
     * @return number of words
     */
    int uniqueCount(BTNode *node);


};

#endif //BINARY_TREE_H