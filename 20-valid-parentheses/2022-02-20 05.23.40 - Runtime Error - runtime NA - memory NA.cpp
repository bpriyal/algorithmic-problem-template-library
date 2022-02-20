class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> masterList({
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        });
        
        for (char c : s) {
            if ( c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (masterList[st.top()] != c) return false;
                st.pop();
            }
        }
        
        return st.empty()? true:false;
    }
};