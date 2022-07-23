class Solution {
    void populateStack(stack<char> &st, const string &s) {
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '#' && !st.empty()) st.pop();
            else st.push(s[i]);
        }
    }
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_st;
        stack<char> t_st;
        
        populateStack(s_st, s);
        populateStack(t_st, t);
        
        return s_st == t_st;
    }
};