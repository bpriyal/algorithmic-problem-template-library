/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
      if (!head) { // 0 sized
        Node* node = new Node(insertVal);
        node->next = node;
        return node;
      }
      if (head->next == head) { // 1 sized
        Node* node = new Node(insertVal);
        node->next = head;
        head->next = node;
        return head;
      }

      Node* prev = head;
      Node* next = head->next;

      while (next != head) {
        if (insertVal >= prev->val && insertVal <= next->val) {
          Node* node = new Node(insertVal);
          node->next = next;
          prev->next = node;
          return head;
        } else if (prev->val > next->val && (insertVal <= next->val || insertVal >= prev->val)) {
          Node* node = new Node(insertVal);
          node->next = next;
          prev->next = node;
          return head;
        }
        prev = prev->next;
        next = next->next;
      }

      // if not returned so far then all elements are equal. Insert at head
      Node* node = new Node(insertVal);
      node->next = next;
      prev->next = node;
    
      return head;
    }
};