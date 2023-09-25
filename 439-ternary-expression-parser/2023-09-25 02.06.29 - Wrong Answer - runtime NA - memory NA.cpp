class Solution {
public:
    string parseTernary(string expression) {
        int size = expression.size();
        stack<char> st;
        int i = 0;
        while (i < size) {
            cout<<i<<endl;
            if (i < size - 1 && expression[i+1] == '?') {
                st.push(tolower(expression[i]));
                i += 2;
                continue;
            }
            if (expression[i] == ':') {
                ++i;
                continue;
            }
            if (islower(st.top())) {
                cout<<"here1"<<endl;
                st.push(expression[i]);
                ++i;
            } else {
                cout<<"here2"<<endl;
                char operand1 = st.top();
                cout<<"operand1: "<<operand1<<endl;
                st.pop();
                char oper = st.top();
                cout<<"oper: "<<oper<<endl;
                st.pop();
                st.emplace(oper == 't'? operand1 : expression[i]);
                ++i;
                cout<<"here11111"<<endl;
            }
        }
        cout<<st.size()<<endl;
        while (!st.empty()) {
            if (st.size() == 1) break;
            char operand2 = st.top(); st.pop();
            char operand1 = st.top(); st.pop();
            char oper = st.top(); st.pop();
            st.emplace(oper == 't'? operand1 : operand2);
        }
        string result;
        result.push_back(st.top());
        return result;
    }
};