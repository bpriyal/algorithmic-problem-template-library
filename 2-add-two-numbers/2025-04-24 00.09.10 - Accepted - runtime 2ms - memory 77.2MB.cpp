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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry = 0;
      ListNode* temp1 = l1;
      ListNode* temp2 = l2;
      ListNode* newHead = nullptr;
      ListNode* prev = nullptr;

      while (temp1 || temp2 || carry != 0) {
        int sum = carry;
        if (temp1) {
          sum += temp1->val;
          temp1 = temp1->next;
        }
        if (temp2) {
          sum += temp2->val;
          temp2 = temp2->next;
        }
        carry = sum / 10;
        auto node = new ListNode(sum % 10);
        if (!newHead) newHead = node;

        if (!prev) prev = node;
        else prev->next = node;
        prev = node;
      }

      // if (carry) prev->next = new ListNode(carry);

      return newHead;
    }
};