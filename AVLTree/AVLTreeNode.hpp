#ifndef _AVL_TREE_NODE_HPP_
#define _AVL_TREE_NODE_HPP_

#include <iostream>

class AVLTreeNode
{
private:
    int _data;
    AVLTreeNode *_left;
    AVLTreeNode *_right;
    AVLTreeNode *_parent;

    int _height;
public:
    AVLTreeNode() : _data(0), _left(nullptr), _right(nullptr), _parent(nullptr), _height(1) {}
    AVLTreeNode(int value) : _data(value), _left(nullptr), _right(nullptr), _parent(nullptr), _height(1) {}

    int data() const {return _data;}
    int& data() {return _data;}

    AVLTreeNode* left() const {return _left;}
    AVLTreeNode* &left() {return _left;}

    AVLTreeNode* right() const {return _right;}
    AVLTreeNode* &right() {return _right;}

    AVLTreeNode* parent() const {return _parent;}
    AVLTreeNode* &parent() {return _parent;}

    int height() const {return _height;}
    int& height() {return _height;}


    bool isLeaf() const { return !_left && !_right; }//{return ( (_left==nullptr) && (_right==nullptr) );}
    bool isRoot() const { return !_parent; } // (_parent==nullptr)

    int depth() const;

    std::ostream& print(std::ostream &toStream) const;
};








#endif
