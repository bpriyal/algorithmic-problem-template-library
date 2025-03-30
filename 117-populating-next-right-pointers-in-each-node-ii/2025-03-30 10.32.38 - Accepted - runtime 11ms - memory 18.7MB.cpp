/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    Node* leftMost = nullptr;
    Node* prev = nullptr;

    void processChild(Node* node) {
      if (!node) return;
      if (prev) prev->next = node;
      else leftMost = node;
      prev = node;
    }

public:
    Node* connect(Node* root) {
      if (!root) return nullptr;

      leftMost = root;

      while (leftMost) {
        Node* curr = leftMost;
        leftMost = nullptr;
        while (curr) {
          processChild(curr->left);
          processChild(curr->right);
          curr = curr->next;
        }
        prev = nullptr;
      }

      return root;
    }
};