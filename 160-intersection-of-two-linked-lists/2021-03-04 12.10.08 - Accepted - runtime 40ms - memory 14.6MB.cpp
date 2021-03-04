/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0,sizeB = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        
        while(tempA != nullptr) {
            ++sizeA;
            tempA = tempA->next;
        }
        
        while(tempB != nullptr) {
            ++sizeB;
            tempB = tempB->next;
        }
        
        tempA = headA;
        tempB = headB;
        if (sizeA > sizeB) {
            for(int i = 0;i < sizeA-sizeB;++i) {
                tempA = tempA->next;
            }
        } else {
            for(int i = 0;i < sizeB-sizeA;++i) {
                tempB = tempB->next;
            }
        }
        
        while(tempA && tempB) {
            if (tempA == tempB) {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return nullptr;
    }
};