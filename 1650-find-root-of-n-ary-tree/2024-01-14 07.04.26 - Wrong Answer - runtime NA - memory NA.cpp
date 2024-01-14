/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
struct Comp {
    int operator()(const Node* n1, const Node* n2) const {
        return n1->val < n2->val;
    }
};
class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int size = tree.size();
        std::map<Node*, bool, Comp> cache;
        for (auto* node : tree) {
            cache[node] = false;
            for (auto* childNode : node->children) cache[childNode] = true;
        }
        for (auto [nodePtr, isChild] : cache) if (!isChild) return nodePtr;
        return nullptr;
    }
};