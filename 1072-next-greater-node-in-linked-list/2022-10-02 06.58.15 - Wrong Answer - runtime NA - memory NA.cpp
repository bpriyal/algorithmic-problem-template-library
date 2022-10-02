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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        unordered_map<int, int> map;
        ListNode* temp = head;
        vector<int> result;
        
        while (temp) {
            while (!st.empty() && st.top() < temp->val) {
                map[st.top()] = temp->val;
                st.pop();
            }
            
            st.push(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        while (temp) {
            result.push_back(map.find(temp->val) == map.end() ? 0 : map[temp->val]);
            temp = temp->next;
        }
        
        return result;
    }
};