class Solution {
public:
    string parseTernary(string expression) {
        int size = expression.size();
        stack<char> st;
        int i = size - 1;
        while (i >= 0) {
            char curr = expression[i];
            if (curr == 'T' || curr == 'F' || isdigit(curr)) st.emplace(curr);
            else if (curr == '?') {
                char oper = expression[i-1];
                char operand1 = st.top(); st.pop();
                char operand2 = st.top(); st.pop();
                st.emplace(oper == 'T'? operand1 : operand2);
                --i;
            }
            --i;
        }
        return string(1, st.top());
    }
};