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
        
        st.pop_back();
        if (pattern.size() != st.size()) {
            return false;
        }
        
        int i = 0;
        for(auto p:pattern) {
            if (cache.find(p) != cache.end()) {
                if (st[i] != cache[p]) {
                    return false;
                }
            } else {
                if (strings.find(st[i]) != strings.end()) {
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