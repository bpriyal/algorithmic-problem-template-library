class Solution {
public:
    bool isEqual(const vector<int>& a,const vector<int>& b) {
        cout<<"here"<<endl;
        for (int i=0;i<26;++i) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        /*unordered_map<char,int> cache,temp;
        vector<int> result;
        if (s_size == 0) return result;
        bool flag = false;
        for(auto& x:p) {
            ++cache[x];
        }
        int i = 0;
        while (i<s_size-p_size+1) {
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
            if(!flag) {
                result.push_back(i);
                i += p_size;
            } else {
                ++i;
            }
        }
        return result;*/
        
        /*solution 2 
        
        vector<int> p_cache(26,0);
        vector<int> s_cache(26,0);
        int i;
        vector<int> result;
        if (s_size < p_size) return result;
        for(i=0;i<p_size;++i) {
            ++p_cache[p[i]-'a'];
            ++s_cache[s[i]-'a'];
        }
        for(i=p_size;i<s_size;++i) {
            cout<<"before if:"<<endl;
            if(isEqual(s_cache,p_cache)) {
                result.push_back(i-p_size);
            }
            cout<<"here2"<<endl;
            ++s_cache[s[i]-'a'];
            --s_cache[s[i-p_size]-'a'];
        }
        if(isEqual(s_cache,p_cache)) result.push_back(i-p_size);
        return result;
        
        solution 2*/
        
        vector<int> p_cache(26,0);
        vector<int> s_cache(26,0);
        int i;
        vector<int> result;
        if (s_size < p_size) return result;
        for(i=0;i<p_size;++i) {
            ++p_cache[p[i]-'a'];
            ++s_cache[s[i]-'a'];
        }
        for(i=p_size;i<s_size;++i) {
            cout<<"before if:"<<endl;
            if(s_cache == p_cache) {
                result.push_back(i-p_size);
            }
            cout<<"here2"<<endl;
            ++s_cache[s[i]-'a'];
            --s_cache[s[i-p_size]-'a'];
        }
        if(s_cache == p_cache) result.push_back(i-p_size);
        return result;
    }
};