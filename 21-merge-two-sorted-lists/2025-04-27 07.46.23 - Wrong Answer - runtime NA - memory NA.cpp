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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (!list1) return list2;
      if (!list2) return list1;
      ListNode* temp1 = list1;
      ListNode* temp2 = list2;
      ListNode* newHead = nullptr;
      ListNode* prev = nullptr;

      while (temp1 && temp2) {
        if (temp1->val <= temp2->val) {
          if (!newHead) newHead = temp1;
          if (prev) prev->next = temp1;
          prev = temp1;
          temp1 = temp1->next;
        } else {
          if (!newHead) newHead = temp1;
          if (prev) prev->next = temp2;
          prev = temp2;
          temp2 = temp2->next;
        }
      }
      if (temp1) prev->next = temp1;
      if (temp2) prev->next = temp2;
      return newHead;
    }
};