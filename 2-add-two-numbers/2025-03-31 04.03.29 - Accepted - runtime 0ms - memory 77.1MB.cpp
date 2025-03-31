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
    // ListNode* reverseLinkedList(ListNode* l) {
    //   ListNode* prev = nullptr;
    //   ListNode* temp = l;

    //   while (temp) {
    //     ListNode* t = temp->next;
    //     temp->next = prev;
    //     prev = temp;
    //     temp = t;
    //   }

    //   return prev;
    // }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      // auto newL1 = reverseLinkedList(l1);
      // auto newL2 = reverseLinkedList(l2);
      ListNode* outputHead = nullptr;
      ListNode* temp = nullptr;
      int carry = 0;

      while (l1 && l2) {
        int outNodeVal = carry + l1->val + l2->val;
        if (outNodeVal > 9) {
          carry = outNodeVal / 10;
          outNodeVal %= 10;
        } else carry = 0;
        auto* node = new ListNode(outNodeVal);
        if (temp) temp->next = node;
        else outputHead = node;
        temp = node;
        l1 = l1->next;
        l2 = l2->next;
      }

      ListNode* remainingNode = l1 ? l1 : l2 ? l2 : nullptr;
      while (remainingNode) {
        int outNodeVal = carry + remainingNode->val;
        if (outNodeVal > 9) {
          carry = outNodeVal / 10;
          outNodeVal %= 10;
        } else carry = 0;
        auto* node = new ListNode(outNodeVal);
        temp->next = node;
        temp = node;
        remainingNode = remainingNode->next;
      }

      if (carry) {
        auto* node = new ListNode(carry);
        temp->next = node;
      }

      return outputHead;
    }
};