#ifndef BTNODE_H
#define BTNODE_H

#include <string>

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

    BTNode *getParent() const;

    BTNode *getLeft() const;

    void setHeight(int height);

    BTNode *getRight() const;

    std::string getElement() const;

    int getCopies() const;

    int getHeight() const;

    void setParent(BTNode *parent);

    void setLeft(BTNode *left);

    void setRight(BTNode *right);

    void setElement(const std::string &element);

    void setCopies(int);

    void incHeight();

    BTNode &operator=(const BTNode &);

};

#endif //BTNODE_H