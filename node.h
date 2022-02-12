#ifndef __NODE_H
#define __NODE_H

#include <sstream>
#include <string>

using std::string;
using std::stringstream;

class Node {
 private:
  string visualize(Node* root, stringstream& json);
  void generateNodesJSON(Node* root, stringstream& json);
  void generateEdgesJSON(Node* root, stringstream& json);

 public:
  int val;
  Node* left;
  Node* right;
  string visualization;

  Node(int val);
  string visualize();
};

#endif /* __NODE_H */
