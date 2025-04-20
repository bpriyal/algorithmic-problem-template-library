/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> oldToNewNodeMap;
    Node* util(Node* node) {
      if (!node) return nullptr;
      if (const auto it = oldToNewNodeMap.find(node); it != oldToNewNodeMap.end()) return it->second;

      auto newNode = new Node(node->val);
      oldToNewNodeMap.emplace(node, newNode);
      for (auto neighbor : node->neighbors) {
        newNode->neighbors.emplace_back(util(neighbor));
      }
      return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
      return util(node);
    }
};