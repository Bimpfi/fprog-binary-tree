#include "BinaryTree.h"

BinaryTree::BinaryTree(int root_value) : root(new Node(root_value)) {
  this->root->visualize();
}

void BinaryTree::add(int value, Node** root) {
  if (*root == nullptr) {
    *root = new Node(value);
  }

  if (value < (*root)->val) {
    this->add(value, &(*root)->left);
  } else if (value > (*root)->val) {
    this->add(value, &(*root)->right);
  }
  this->root->visualize();
}

void BinaryTree::add(int value) {
  this->add(value, &(this->root));
  this->root->visualize();
}

Node** BinaryTree::find(int value) { this->find(value, &(this->root)); }

Node** BinaryTree::find(int value, Node** root) {
  if (*root == nullptr) {
    return nullptr;
  }

  if (value < (*root)->val) {
    this->find(value, &(*root)->left);
  } else if (value > (*root)->val) {
    this->find(value, &(*root)->right);
  } else {
    return root;
  }
}

bool BinaryTree::remove(int value) {
  Node** node = this->find(value);
  Node* parent_node = this->root;

  if (node == nullptr) {
    return true;
  }

  while (parent_node->left != *node && parent_node->right != *node) {
    parent_node =
        (value < parent_node->val) ? parent_node->left : parent_node->right;
  }

  if (value < parent_node->val) {
    delete *node;
    parent_node->left = nullptr;
  } else {
    delete *node;
    parent_node->right = nullptr;
  }

  this->root->visualize();
}