class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        int i = 0;
        int size = s.size();
        int diff = abs('a' - 'A');
        
        for (int i = 0; i < size; ++i) {
            if (st.empty()) {
                st.push(s[i]);
            }
            else if (abs(st.top() - s[i]) == diff) {
                st.pop();
            }
            else {  
                st.push(s[i]);
            }
        }
                     
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
                     
        return result;
    }
};