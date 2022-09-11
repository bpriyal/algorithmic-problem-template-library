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
        if (!head || !head->next || !k) return head;
        
        int size = 0;
        ListNode* temp = head;
        
        while (temp) {
            ++size;
            temp = temp->next;
        }
        if (!(k%size)) return head;
        
        int shift = size - (k % size);
        
        temp = head;
        while (shift > 1) {
            temp = temp->next;
            --shift;
        }
                
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        temp = newHead;
        
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = head;
        
        return newHead;
    }
};