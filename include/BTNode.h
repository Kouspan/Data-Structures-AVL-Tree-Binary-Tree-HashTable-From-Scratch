#ifndef BTNODE_H
#define BTNODE_H

#include <string>
/**
 * Binary tree node
 */
class BTNode {
private:
    std::string element;
    BTNode *parent;
    BTNode *right;
    BTNode *left;
    int copies;
    int height;
public:
    BTNode();

    explicit BTNode(const std::string &element);

    std::string getElement() const;

    BTNode *getParent() const;

    BTNode *getLeft() const;

    BTNode *getRight() const;

    int getCopies() const;

    int getHeight() const;

    void setElement(const std::string &element);

    void setParent(BTNode *parent);

    /**
    * sets the left children and also sets this as it's parent
    * @param left
    */
    void setLeft(BTNode *left);

    /**
     * sets the right children and also sets this as it's parent
     * @param right
     */
    void setRight(BTNode *right);

    void setCopies(int);

    void setHeight(int var);
};

#endif //BTNODE_H