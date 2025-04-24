/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
      if (!node) return nullptr;
      if (node->parent && node->parent->left == node) return node->parent;
      if (!node->right) return nullptr;
      Node* temp = node->right;
      while (temp->left) {
        temp = temp->left;
      }
      return temp;
    }
};