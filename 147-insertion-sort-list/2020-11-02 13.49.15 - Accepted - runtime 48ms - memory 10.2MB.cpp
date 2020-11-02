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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sortedNode = new ListNode(INT_MIN);
        while(head != nullptr) {
            ListNode *temp = sortedNode;
            while(temp->next && temp->next->val < head->val) {
                temp = temp->next;
            }
            ListNode *temp2 = head->next;
            head->next = temp->next;
            temp->next = head;
            head = temp2;
        }
        return sortedNode->next;
    }
};