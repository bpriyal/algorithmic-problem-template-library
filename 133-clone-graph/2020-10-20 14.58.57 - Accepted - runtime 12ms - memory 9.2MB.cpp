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
    Node* util(Node* node,unordered_map<Node*,Node*> &cache) {
        if(node == nullptr) {
            return node;
        }
        Node* root = nullptr;
        Node* temp = nullptr;
        vector<Node*> neigh;
        if (cache.find(node) == cache.end()) {
            root = new Node(node->val);
            cache[node] = root;
            for(auto n:node->neighbors) {
                temp = util(n,cache);
                neigh.push_back(temp);
            }
            root->neighbors = neigh;
        } else {
            return cache[node];
        }
        return root;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> cache;
        return util(node,cache);
    }
};