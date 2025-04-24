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
      if (node->right) { // inorder successor definitely lies below
        Node* temp = node->right;
        while (temp->left) temp = temp->left;
        return temp;
      }
      // Else go to the parent which is a left child
      Node* temp = node;
      while (temp->parent) {
        if (temp->parent->left == temp) return temp->parent;
        temp = temp->parent;
      }
      return nullptr;
    }
};