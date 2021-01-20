class Solution {
    bool checkTopOfStack(stack<char> &st,char typeOfBracket) {
        char stackTop = st.top();
        st.pop();
        return stackTop == typeOfBracket;
    }
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c:s) {
            bool topMatches;
            if (c == ')') {
                topMatches = checkTopOfStack(st,'(');
                if (!topMatches) {
                    return false;
                }
            } else if (c == '}') {
                topMatches = checkTopOfStack(st,'{');
                if (!topMatches) {
                    return false;
                }
            } else if (c == ']') {
                topMatches = checkTopOfStack(st,'[');
                if (!topMatches) {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};