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
    Node* lowestCommonAncestor(Node* p, Node * q) {
      unordered_set<Node*> pPathCache;
      Node* temp = p;

      while (temp) {
        pPathCache.emplace(temp);
        temp = temp->parent;
      }

      temp = q;
      while (temp) {
        if (pPathCache.contains(temp)) return temp;
        temp = temp->parent;
      }

      return nullptr;
    }
};