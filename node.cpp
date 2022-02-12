#include "node.h"

Node::Node(int val)
    : val(val), left(nullptr), right(nullptr), visualization("") {}

string Node::visualize() {
  stringstream json;
  this->visualize(this, json);

  return json.str();
}

string Node::visualize(Node* root, stringstream& json) {
  Node* currentLeft = root->left;
  Node* currentRight = root->right;
  stringstream str;
  stringstream nodes("\"nodes\": [");
  stringstream edges("\"edges\": [");

  str << "{";
  str << "\"kind\": { \"graph\": true},";
  str << "\"nodes\": [";
  this->generateNodesJSON(root, str);
  str << "],";
  str << "\"edges\": [";
  this->generateEdgesJSON(root, str);
  str << "]";
  // str << "\"nodes\": [{\"id\": \"1\"}, {\"id\": \"2\"}],";
  // str << "\"edges\": [ {\"from\":\"1\",\"to\":\"2\",\"color\":\""
  //        "red\"}]";
  str << "}";
  // cout << str.str();
  this->visualization = str.str();
  return str.str();
}

void Node::generateEdgesJSON(Node* root, stringstream& json) {
  if (root->left != nullptr) {
    json << "{\"from\":\"" << root->val << "\", \"to\":\"" << root->left->val
         << "\", \"label\": \"left\"}";
  }

  if (root->left != nullptr && root->right != nullptr) {
    json << ", ";
  }

  if (root->right != nullptr) {
    json << "{\"from\":\"" << root->val << "\", \"to\":\"" << root->right->val
         << "\", \"label\": \"right\"}";
  }

  if (root->left != nullptr &&
      (root->left->left != nullptr || root->left->right != nullptr)) {
    json << ", ";
    this->generateEdgesJSON(root->left, json);
  }

  if (root->right != nullptr &&
      (root->right->left != nullptr || root->right->right != nullptr)) {
    json << ", ";
    this->generateEdgesJSON(root->right, json);
  }
}

void Node::generateNodesJSON(Node* root, stringstream& json) {
  json << "{\"id\": \"" << root->val << "\"}";
  if (root->left != nullptr) {
    json << ",";
    generateNodesJSON(root->left, json);
  }

  if (root->right != nullptr) {
    json << ",";
    generateNodesJSON(root->right, json);
  }
}