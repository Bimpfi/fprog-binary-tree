#include <iostream>
#include <sstream>
#include <string>

#include "BinaryTree.h"

using std::cout;
using std::string;
using std::stringstream;

int main(int argc, char const* argv[]) {
  Node** root;
  BinaryTree tree(42);

  Node** search = nullptr;
  Node** search1 = nullptr;

  root = tree.getRoot();

  tree.add(10);
  tree.add(76);
  tree.add(1);
  tree.add(8);
  tree.add(9);
  tree.add(1234);
  tree.add(123);
  tree.add(12378);
  tree.add(13000);
  tree.add(1500);
  tree.add(-5);
  // tree.remove(1234); 0x1f1990
  // tree.remove(42); 0x1f1a70
  // tree.remove(76);

  search = tree.find(8);
  search1 = tree.find(12);

  return 0;
}
