#ifndef _AVL_TREE_HPP_
#define _AVL_TREE_HPP_

#include "AVLTreeNode.hpp"

#include <iostream>

class AVLTree
{
private:
    AVLTreeNode *_root;
public:
    AVLTree() : _root(nullptr) {}

    AVLTreeNode* find(int valToFind) const;

    void insert(int newVal);
    void remove(int existingVal);

    std::ostream& print(std::ostream &os) const;
};

#endif
