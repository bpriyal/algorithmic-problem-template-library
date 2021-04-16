class Solution {
public:
    string removeDuplicates(string s, int k) {
        int size = s.size();
        
        stack<pair<char,int>> st;
        st.push({s[0],1});
        
        for(int i = 1;i < size;++i) {
            if (!st.empty()) {
                pair<char,int> p = st.top();
                //printf("current char:%c||last char:%c||last freq:%d\n",s[i],p.first,p.second);
                if (p.first == s[i]) {
                    if (p.second == k - 1) {
                        while (p.second > 0) {
                            //cout<<"in loop"<<endl;
                            st.pop();
                            --p.second;
                        }
                    } else {
                        st.push({s[i],p.second+1});
                    }
                } else {
                    st.push({s[i],1});
                }
            } else {
                st.push({s[i],1});
            }
        }
        
        string result = {};
        
        while (!st.empty()) {
            result += st.top().first;
            st.pop();
        }
        
        reverse(result.begin(),result.end());
        
        return result;
    }
};