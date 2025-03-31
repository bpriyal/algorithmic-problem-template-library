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
    ListNode* outputHead = nullptr;
    ListNode* temp = nullptr;
    int carry = 0;

    void util(int sum) {
      if (sum > 9) {
        carry = sum / 10;
        sum %= 10;
      } else carry = 0;
      auto* node = new ListNode(sum);
      if (temp) temp->next = node;
      else outputHead = node;
      temp = node;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

      while (l1 && l2) {
        util(carry + l1->val + l2->val);
        l1 = l1->next;
        l2 = l2->next;
      }

      ListNode* remainingNode = l1 ? l1 : l2 ? l2 : nullptr;
      while (remainingNode) {
        util(carry + remainingNode->val);
        remainingNode = remainingNode->next;
      }

      if (carry) {
        util(carry);
      }

      return outputHead;
    }
};