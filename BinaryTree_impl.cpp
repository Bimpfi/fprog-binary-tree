#include "BinaryTree.h"

BinaryTree::BinaryTree(int root_value) : root(new Node(root_value)) {
  this->root->visualize();
}

void BinaryTree::add(int value) {
  if (this->root == nullptr) {
    this->root = new Node(value);
  } else {
    this->add(value, &(this->root));
  }
  this->root->visualize();
}

void BinaryTree::add(int value, Node** root) {
  if (*root == nullptr) {
    *root = new Node(value);
  } else {
    ((*root)->val > value) ? this->add(value, &((*root)->left))
                           : this->add(value, &((*root)->right));
  }
}

Node** BinaryTree::find(int value) { return this->find(value, &(this->root)); }

Node** BinaryTree::find(int value, Node** root) {
  if ((*root) == nullptr) {
    return nullptr;
  }

  if ((*root)->val == value) {
    return root;
  }

  return (value < (*root)->val) ? this->find(value, &(*root)->left)
                                : this->find(value, &(*root)->right);
}

bool BinaryTree::remove(int value) {
  Node** node = this->find(value);
  Node* oldNode = (node == nullptr) ? nullptr : *node;
  Node* it = nullptr;
  Node* it_prev = nullptr;

  if (oldNode == nullptr) {
    return false;
  }

  it = oldNode->right;

  while (it->left != nullptr) {
    it_prev = it;
    it = it->left;
  }

  oldNode->val = it->val;
  if (it_prev != nullptr) {
    it_prev->left = it->right;
  } else {
    oldNode->right = it->right;
  }

  it->right = nullptr;

  if (it != this->root) {
    delete it;
  }

  this->root->visualize();
}