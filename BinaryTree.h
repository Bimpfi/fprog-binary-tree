#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include "node.h"

class BinaryTree {
 private:
  Node* root;
  void add(int value, Node** root);
  Node** find(int value, Node** root);

 public:
  BinaryTree(int root_value);
  void add(int value);
  bool remove(int value);
  Node** find(int value);
  Node** getRoot() { return &(this->root); }
};

#endif /* __BINARY_TREE_H */
