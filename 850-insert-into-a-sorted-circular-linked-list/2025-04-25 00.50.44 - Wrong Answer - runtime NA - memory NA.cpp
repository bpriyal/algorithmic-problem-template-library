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
      Node* temp = head;
      // Empty list
      if (!temp) {
        auto node = new Node(insertVal);
        node->next = node;
        return node;
      }
      // single node list
      if (temp->next == temp) {
        auto node = new Node(insertVal);
        node->next = temp;
        temp->next = node;
        return temp;
      }
      // 2 or more
      temp = head->next;
      while (temp != head) {
        if (temp->next->val >= temp->val) {
          if (temp->val <= insertVal && insertVal <= temp->next->val) {
            auto node = new Node(insertVal);
            node->next = temp->next;
            temp->next = node;
            return head;
          }
        } else {
          if (temp->val <= insertVal || insertVal <= temp->next->val) {
            auto node = new Node(insertVal);
            node->next = temp->next;
            temp->next = node;
            return head;
          }
        }
        temp = temp->next;
      }
      return nullptr;
    }
};