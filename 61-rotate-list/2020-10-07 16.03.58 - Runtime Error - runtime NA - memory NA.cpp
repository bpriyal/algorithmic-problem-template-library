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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int size =0;
        while (temp) {
            ++size;
            temp = temp->next;
        }
        if (k%size == 0) {
            return head;
        }
        ListNode *temp1 = head;
        while(temp1->next) {
           temp1 = temp1->next;
        }
        temp = head;
        for(int i=0;i<size-(k%size)-1;++i) {
            temp = temp->next;
        }
        temp1->next = head;
        head = temp->next;
        temp->next = nullptr;
        
        return head;
    }
};