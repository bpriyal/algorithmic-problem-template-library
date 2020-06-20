class Solution {
    string lcs(string s1,string s2){
        int s1_ = s1.size();
        int s2_ = s2.size();
        int i =0;
        while(i != s1.size() || i != s2.size()) {
            if (s1[i] != s2[i]) {
                break;
            }
            ++i;
        }
        return s1.substr(0,i);
    }
public:
    string longestDupSubstring(string S) {
        int size = S.size();
        vector<string> cache(size);
        for(int i =0;i<size;++i) {
            cache[i] = S.substr(i,size-i);
        }
        sort(cache.begin(),cache.end());
        string result;
        for(int i = 0;i<size-1;++i) {
            string temp = lcs(cache[i],cache[i+1]);
            if (temp.size() > result.size()) {
                result = temp;
            }
        }
        return result;
    }
};