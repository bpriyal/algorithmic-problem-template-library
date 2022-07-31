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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* oddPos = head;
        ListNode* evenPos = head->next;
        ListNode* evenHead = evenPos;
        
        while(oddPos && evenPos && evenPos->next) {
            oddPos->next = evenPos->next;
            oddPos = oddPos->next;
            
            evenPos->next = oddPos->next;
            evenPos = evenPos->next;
        }
        
        oddPos->next = evenHead;
        
        return head;
    }
};