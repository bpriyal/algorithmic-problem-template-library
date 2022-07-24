class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        stack<int> frequency;
        
        for(const char& c : s) {
            if (c == ']') {
                string temp = "";
                
                while(st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                
                st.pop();
                reverse(temp.begin(), temp.end());
                int f = frequency.top();
                frequency.pop();
                
                for(int i = 0; i < f;++i) {
                    for(char t : temp) st.push(t);
                }
            }
            else if (isdigit(c)) frequency.push(c - '0');
            else st.push(c);
        }
        
        string result = "";
        
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};