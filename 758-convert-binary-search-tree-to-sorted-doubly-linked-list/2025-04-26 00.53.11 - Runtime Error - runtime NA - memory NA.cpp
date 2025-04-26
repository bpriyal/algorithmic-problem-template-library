/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node* first = nullptr;
    Node* last = nullptr;
    void dfs(Node* root) {
      if (!root) return;
      dfs(root->left);
      if (last) {
        last->right = root;
        root->left = last;
      } else first = root;
      last = root;
      dfs(root->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
      dfs(root);
      first->left = last;
      last->right = first;
      return first;
    }
};