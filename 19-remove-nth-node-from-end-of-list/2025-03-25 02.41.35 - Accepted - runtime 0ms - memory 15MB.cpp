/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* temp = head;
      int size = 0;

      while (temp) {
        ++size;
        temp = temp->next;
      }

      int jumps = size - n;
      ListNode* prev = nullptr;
      ListNode* curr = head;
      if (jumps == 0) {
        head = head->next;
        // free(curr);
        curr = nullptr;
        return head;
      }

      while (jumps) {
        prev = curr;
        curr = curr->next;
        --jumps;
      }

      prev->next = curr->next;
      // free(curr);
      curr = nullptr;

      return head;
    }
};