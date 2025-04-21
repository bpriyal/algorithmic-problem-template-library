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
       ListNode* prev = nullptr;
       ListNode* temp = head;

       for (int i = 0; i < n; ++i) temp = temp->next;

       while (temp) {
        if (!prev) prev = head;
        else prev = prev->next;
        temp = temp->next;
       }

       if (prev == nullptr) return head->next;
       prev->next = prev->next->next;
       return head;
    }
};