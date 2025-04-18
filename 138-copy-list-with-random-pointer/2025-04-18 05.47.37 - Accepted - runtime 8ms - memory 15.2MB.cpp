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
    unordered_map<Node*, Node*> oldToNewNodeMap;
    Node* util(Node* original) {
      if (!original) return nullptr;
      auto it = oldToNewNodeMap.find(original);
      if (it != oldToNewNodeMap.end()) return it->second;

      Node* node = new Node(original->val);
      oldToNewNodeMap.try_emplace(original, node);
      node->next = util(original->next);
      node->random = util(original->random);
      return node;
    }
public:
    Node* copyRandomList(Node* head) {
      if (!head) return nullptr;
      Node* newHead = new Node(head->val);
      oldToNewNodeMap.try_emplace(head, newHead);
      newHead->next = util(head->next);
      newHead->random = util(head->random);
      return newHead;
    }
};