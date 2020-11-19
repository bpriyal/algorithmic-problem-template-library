class Solution {   
public:
    string decodeString(string s) {
        stack<string> st;
        int size = s.size();
        
        for(char c:s) {
            if (c != ']') {
                string s(1,c);
                st.push(s);
            } else {
                string temp = "";
                while(!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && st.top() > "1" && st.top() <="9") {
                    num = st.top() + num;
                    st.pop();
                }
                if (num.empty()) {
                    num = "1";
                }
                int frequency = stoi(num);
                string temp2 = "";
                while(frequency) {
                    temp2 += temp;
                    --frequency;
                }
                st.push(temp2);
            }
        }
        string result = "";
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};