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
        
        vector<string> st;
        
        for (int i = 0; i < size; ++i) {
            if (s[i] == ' ') continue;
            if (operators.count(s[i])) {
                if (s[i] == '*' || s[i] == '/') {
                    char op = s[i];
                    ++i;
                    
                    int first = stoi(st.back());
                    cout<<first<<endl;
                    int second = stoi(getNumber(s, i));
                    
                    st.pop_back();
                    
                    op == '*'? st.push_back(to_string(first*second)) : st.push_back(to_string(first/second));
                } else {
                    st.push_back(string(1,s[i]));
                }
            } else {
                st.push_back(getNumber(s, i));
            }
        }
        
        int s_size = st.size();
        int i = 0;
        while (i <= s_size - 3) {
            int first = stoi(st[i++]);
            string op = st[i++];
            int second = stoi(st[i]);
            
            cout<<"first: "<<first<<", op: "<<op<<", second: "<<second<<endl;
            
            st[i] = op == "+"? to_string(first + second) : to_string(first - second);
        }
        
        return stoi(st.back());
    }
};