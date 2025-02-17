#include "AVLTree.hpp"

using namespace std;

AVLTreeNode* findHelper(AVLTreeNode *inSubTree, int valToFind)
{
    if (!inSubTree)
        return nullptr;

    if (inSubTree->data() == valToFind)
        return inSubTree;

    if (inSubTree->data() < valToFind)
        return findHelper(inSubTree->right(), valToFind);

    // must be in left subtree (or we would already have returned)
    return findHelper(inSubTree->left(), valToFind);
}

AVLTreeNode*
AVLTree:: find(int valToFind) const
{
    return findHelper(_root, valToFind);
}

int getHeight(const AVLTreeNode *subTree)
{
  if (!subTree)
    return 0;
  else
    return subTree->height();
}

// a single rotation , pulling up left child
//  k2 - the current root. 
//  returns the new root. 
AVLTreeNode* rotateRight(AVLTreeNode *k2)
{
  AVLTreeNode *subtreeParent = k2->parent();
  // NOTE: See course notes for picture of what k1 and k2 (and Y) mean here
  AVLTreeNode *k1 = k2->left();
  k2->left() = k1->right(); // Y
  k1->right() =  k2;

  // we just moved things around. Update associated subtree heights. 
  k2->height() = 1 + max (getHeight(k2->left()), getHeight(k2->right()) );
  k1->height() = 1 + max (getHeight(k1->left()), getHeight(k2) );

  // fix parent ptrs.
  k2->parent() = k1;
  if (k2->left()) k2->left()->parent()=k2; // patch Y's parent
  k1->parent() = subtreeParent;

  return k1;
}

// a single rotation , pulling up right child
//  k2 - the current root. 
//  returns the new root. 
AVLTreeNode* rotateLeft(AVLTreeNode *k2)
{
  AVLTreeNode *subtreeParent = k2->parent();

  // NOTE: See course notes for picture of what k1 and k2 (and Y) mean here
  AVLTreeNode *k1 = k2->right();
  k2->right() = k1->left(); // Y
  k1->left() =  k2;

  // we just moved things around. Update associated subtree heights. 
  k2->height() = 1 + max (getHeight(k2->left()), getHeight(k2->right()) );
  k1->height() = 1 + max (getHeight(k1->right()), getHeight(k2) );

  // fix parent ptrs.
  k2->parent() = k1;
  if (k2->right()) k2->right()->parent()=k2; // patch Y's parent
  k1->parent() = subtreeParent;

  return k1;
}

AVLTreeNode* doubleWithLeftChild(AVLTreeNode *k3)
{
  AVLTreeNode *k1 = k3->left();
  k3->left() = rotateLeft(k1);
  return rotateRight(k3);
}

AVLTreeNode* doubleWithRightChild(AVLTreeNode *k3)
{
  AVLTreeNode *k1 = k3->right();
  k3->right() = rotateRight(k1);
  return rotateLeft(k3);
}



// intoSubTree -- the subtree into which we want to insert
// returns : updated version of subtree
AVLTreeNode* insertHelper(AVLTreeNode *intoSubTree, int valToAdd)
{
    if (intoSubTree == nullptr) // empty tree!
    {
        AVLTreeNode *newTree = new AVLTreeNode(valToAdd);
        return newTree;
    }
    if (valToAdd < intoSubTree->data() )
    {
        // want to insert in left subtree
        AVLTreeNode *newSubTree = insertHelper(intoSubTree->left(), valToAdd);
        intoSubTree->left() = newSubTree;
        newSubTree->parent() = intoSubTree;

        // might need AVL rotations ... look at children's heights to decide
        int leftHeight = getHeight(intoSubTree->left());
        int rightHeight = getHeight(intoSubTree->right());

        // left imbalance
        if (leftHeight-rightHeight==2) 
	{
	  // is this a left-left imbalance?
	  if (valToAdd < intoSubTree->left()->data() )
	  {
	      intoSubTree=rotateRight(intoSubTree);
	  }
	  // or is it a left-rght imabalance?
	  else
	  {
	      intoSubTree=doubleWithLeftChild(intoSubTree);
	  }
	}
    }
    else if (valToAdd > intoSubTree->data() )
    {
        // want to insert into right subtree
        AVLTreeNode *newSubTree = insertHelper(intoSubTree->right(), valToAdd);
        intoSubTree->right() = newSubTree;
        newSubTree->parent() = intoSubTree;

        // might need AVL rotations ... look at children's heights to decide
        int leftHeight = getHeight(intoSubTree->left());
        int rightHeight = getHeight(intoSubTree->right());

        // check for right imbalance
        if (rightHeight-leftHeight==2) 
	{
	  // is this a right-right imbalance?
	  if (valToAdd >  intoSubTree->right()->data() )
	    {
	      intoSubTree=rotateLeft(intoSubTree);
	    }
	  // or is it a right-left imabalance?
	  else
	    {
	      intoSubTree=doubleWithRightChild(intoSubTree);
	    }
	}
    }
    else // == ... so already found in subtree!!
    {
      
    }

    // now that we've mved things areound, need to update this nodes height. 
    intoSubTree->height() = 1 + max(getHeight(intoSubTree->left()),
				    getHeight(intoSubTree->right()) ); 
    return intoSubTree;
}



void
AVLTree::insert(int newVal)
{
    _root=insertHelper(_root, newVal);
}

AVLTreeNode*
removeHelper(int existingVal, AVLTreeNode *fromSubTree)
{
  // no subtree? no need to remove anything. 
  if (!fromSubTree)
    return nullptr;

  // is node we need to remove in left subtree?
  if (existingVal < fromSubTree->data())
    {
      // recursively remove from left subtree
      fromSubTree->left() = removeHelper(existingVal, fromSubTree->left() );
    }
  else if (existingVal > fromSubTree->data())
    {
      // recursively remove from right subtree
      fromSubTree->right() = removeHelper(existingVal, fromSubTree->right() );
    }
  else // this is the node we want to remove!
    {
      if (fromSubTree->isLeaf())  // 0 children
	{
	  fromSubTree=nullptr;
	}
      else if (fromSubTree->left() && fromSubTree->right() ) // 2 children
	{
          // find the largest node in the left subtree ...
	  AVLTreeNode *toDel = fromSubTree->left();
	  while(toDel->right()!=nullptr)
	    {
	      toDel = toDel->right();
	    }

          // back up largest value in left subtree. 
	  int valueToMove = toDel->data();

          // remove node containing largest value in subtree ...
	  fromSubTree->left()=removeHelper(valueToMove, fromSubTree->left());
          if (fromSubTree->left()) 
            fromSubTree->left()->parent() = fromSubTree;
          // ... but place its value in the node we really want to "remove"
	  fromSubTree->data() = valueToMove;
	}
      else // 1 child
	{
	  if (fromSubTree->left() ) // no right subtree since only 1 child
          {
            fromSubTree->left()->parent() = fromSubTree->parent();
	    fromSubTree = fromSubTree->left();
          }
	  else // only have right child
          {
            fromSubTree->right()->parent() = fromSubTree->parent();
	    fromSubTree = fromSubTree->right();
          }
	}
      
    }

  // no tree left? return NULL
  if (!fromSubTree)
    return nullptr;
  
  // rebalance now if needed
  int balance = getHeight(fromSubTree->left()) -
                getHeight(fromSubTree->right()) ;

  // is the left subtree of height more than 2 bigger than right subtree
  if (balance==2)
    {
      int subBalance = getHeight(fromSubTree->left()->left()) -
	               getHeight(fromSubTree->left()->right());

      // left-left issue
      if (subBalance >= 0)
	{
	  fromSubTree = rotateRight(fromSubTree);
	}
      else // left-right issue
	{
	  fromSubTree = doubleWithLeftChild(fromSubTree);
	}
    }
  
  // is the right subtree of height more than 2 bigger than left subtree
  if (balance==-2)
    {
      int subBalance = getHeight(fromSubTree->right()->left()) -
	               getHeight(fromSubTree->right()->right());

      // right-right issue
      if (subBalance < 0)
	{
	  fromSubTree = rotateLeft(fromSubTree);
	}
      else // left-right issue
	{
	  fromSubTree = doubleWithRightChild(fromSubTree);
	}
    }

  // might have changed heights of children, so update subtree's height
  fromSubTree->height() = 1 + max( getHeight(fromSubTree->left()) ,
				   getHeight(fromSubTree->right()) );
  
  return fromSubTree;
}



void
AVLTree::remove(int existingVal)
{
    AVLTreeNode *toDel = find(existingVal);
    if (!toDel)
    {
        cerr << "Sorry, \"" << existingVal << "\" is not in tree!"
            << endl;
        return;
    }
    _root=removeHelper(existingVal, _root);
}


void inOrderPrint(AVLTreeNode *currNode, ostream &os)
{
    if (currNode==nullptr)
        return;

    inOrderPrint(currNode->right(), os);

    // indent the node properly to display as tree
    for (int indentCount=0; indentCount<currNode->depth(); indentCount++)
        os << "    ";
    currNode->print(os);
    os << "( " << getHeight(currNode->left()) 
       << "   <==>   "
       << getHeight(currNode->right()) << " )";
    os << endl;

    inOrderPrint(currNode->left(), os);
}

std::ostream&
AVLTree::print(std::ostream &someStream) const
{
    inOrderPrint(_root, someStream);
    return someStream;
}







