/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> cache;
    Node* getNewNode(Node* node) {
      if (!node) return nullptr;
      if (auto it = cache.find(node); it != cache.end()) return it->second;
      cache[node] = new Node(node->val);
      return cache[node];
    }
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* oldNode = head;
        Node* newNode = new Node(oldNode->val);
        cache[oldNode] = newNode;
        while (oldNode) {
          newNode->next = getNewNode(oldNode->next);
          newNode->random = getNewNode(oldNode->random);
          newNode = newNode->next;
          oldNode = oldNode->next;
        }
        return cache[head];
    }
};