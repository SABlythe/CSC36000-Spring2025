OPTS = -g -ansi -pedantic -Wall -std=c++20
CC = g++ -c $(OPTS)
LN = g++
OBJS = AVLTree.o AVLTreeNode.o test.o

bt: $(OBJS)
	$(LN) -o bt $(OBJS)

test.o: test.cpp AVLTree.hpp AVLTreeNode.hpp
	$(CC) test.cpp

AVLTree.o: AVLTree.cpp AVLTree.hpp AVLTreeNode.hpp
	$(CC) AVLTree.cpp

AVLTreeNode.o: AVLTreeNode.cpp AVLTreeNode.hpp
	$(CC) AVLTreeNode.cpp

clean:
	/bin/rm -f $(OBJS) bt

