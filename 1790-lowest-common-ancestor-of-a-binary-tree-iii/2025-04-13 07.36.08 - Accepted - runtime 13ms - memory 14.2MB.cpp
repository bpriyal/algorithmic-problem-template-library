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
      // unordered_set<Node*> cache;

      // Node* temp = p;
      // while (temp) {
      //   cache.emplace(temp);
      //   temp = temp->parent;
      // }

      // temp = q;
      // while (temp) {
      //   if (cache.count(temp)) return temp;
      //   temp = temp->parent;
      // }
      // return nullptr;

      Node* tempP = p;
      Node* tempQ = q;

      while (tempP != tempQ) {
        tempP = tempP ? tempP->parent : q;
        tempQ = tempQ ? tempQ->parent : p;
      }

      return tempP;
    }
};

// O(H => logn => N)