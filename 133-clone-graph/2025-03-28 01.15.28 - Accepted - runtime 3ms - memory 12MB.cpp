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
public:
    Node* cloneGraph(Node* node) {
      if (!node) return nullptr;
      if (auto it = oldToNewNodeMap.find(node); it != oldToNewNodeMap.end()) return it->second;

      Node* newNode = new Node(node->val);
      oldToNewNodeMap.try_emplace(node, newNode);
      for (const auto& neighbor : node->neighbors) {
        if (neighbor) newNode->neighbors.emplace_back(cloneGraph(neighbor));
      }
      return newNode;
    }
};