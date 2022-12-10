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
        stack<ListNode*> st1;
        stack<ListNode*> st2;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while (temp1) {
            st1.emplace(temp1);
            temp1 = temp1->next;
        }

        while (temp2) {
            st2.emplace(temp2);
            temp2 = temp2->next;
        }

        int carry = 0;
        ListNode* result = nullptr;
        while (!st1.empty() && !st2.empty()) {
            int res = st1.top()->val + st2.top()->val + carry;

            st1.pop(); st2.pop();

            ListNode* t = new ListNode(res % 10);
            carry = res / 10;
            
            t->next = result;
            result = t;

            cout<<t->val<<endl;
        }

        cout<<"here"<<endl;

        while (!st1.empty()) {
            int res = st1.top()->val + carry;

            st1.pop();

            ListNode* t = new ListNode(res % 10);
            carry = res / 10;

            t->next = result;
            result = t;
        }

        while (!st2.empty()) {
            int res = st2.top()->val + carry;

            st2.pop();

            ListNode* t = new ListNode(res % 10);
            carry = res / 10;

            t->next = result;
            result = t;
        }

        return result;
    }
};