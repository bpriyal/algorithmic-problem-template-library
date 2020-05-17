class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int s_size = s.size();
        int p_size = p.size();
        unordered_map<char,int> cache,temp;
        vector<int> result;
        bool flag = false;
        for(auto& x:p) {
            ++cache[x];
        }
        for(int i = 0;i<s_size;++i) {
            temp = cache;
            flag = false;
            for (int j = i;j<i+p_size;++j) {
                if (temp.find(s[j]) != temp.end() && temp[s[j]] > 0) {
                    --temp[s[j]];
                } else {
                    flag = true;
                    break;
                }
            }
            if(!flag) result.push_back(i);
        }
        return result;
    }
};