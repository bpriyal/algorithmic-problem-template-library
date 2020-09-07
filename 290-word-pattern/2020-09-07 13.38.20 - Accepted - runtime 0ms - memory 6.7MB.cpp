class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> cache;
        set<string> strings;
        vector<string> st;
        
        istringstream ss(str); 
        do {  
            string word; 
            ss >> word;
            st.push_back(word);
        } while (ss);
        //cout<<st.size()<<endl;
        /*for(int i=0;i<st.size();++i) {
            cout<<st[i]<<endl;
        }*/
        st.pop_back();
        if (pattern.size() != st.size()) {
            //cout<<"here2"<<endl;
            return false;
        }
        
        int i = 0;
        for(auto p:pattern) {
            if (cache.find(p) != cache.end()) {
                if (st[i] != cache[p]) {
                    //cout<<"here"<<endl;
                    return false;
                }
            } else {
                if (strings.find(st[i]) != strings.end()) {
                    //cout<<i<<endl;
                    //cout<<"here"<<endl;
                    return false;
                }
                strings.insert(st[i]);
                cache[p] = st[i];
            }
            ++i;
        }
        
        return true;
    }
};