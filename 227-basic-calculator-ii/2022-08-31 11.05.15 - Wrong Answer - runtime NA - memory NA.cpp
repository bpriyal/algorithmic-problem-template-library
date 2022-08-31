class Solution {
    unordered_set<char> operators = {'+', '-', '*', '/'};
    int size;
    
    string getNumber(const string& s, int& i) {
        string num = "";
        while(!operators.count(s[i]) && i < size) {
            if (s[i] == ' ') {
                ++i;
                continue;
            }
            num += s[i];
            ++i;
        }
        --i;
        return num;
    }
public:
    int calculate(string s) {
        size = s.size();
        
        stack<string> st;
        
        for (int i = 0; i < size; ++i) {
            if (s[i] == ' ') continue;
            if (operators.count(s[i])) {
                if (s[i] == '*' || s[i] == '/') {
                    char op = s[i];
                    ++i;
                    
                    int first = stoi(st.top());
                    cout<<first<<endl;
                    int second = stoi(getNumber(s, i));
                    
                    st.pop();
                    
                    op == '*'? st.push(to_string(first*second)) : st.push(to_string(first/second));
                } else {
                    st.push(string(1,s[i]));
                }
            } else {
                st.push(getNumber(s, i));
            }
        }
        cout<<"here1"<<endl;
        while (st.size() >= 3) {
            int second = stoi(st.top());
            st.pop();
            
            string op = st.top();
            st.pop();
            
            int first = stoi(st.top());
            st.pop();
            
            op == "+"? st.push(to_string(first + second)) : st.push(to_string(first - second));
        }
        
        return stoi(st.top());
    }
};