class Solution {
    int result,size;
    
    void util(string &s,int left,int right) {
        while(left >= 0 && right < size && s[left] == s[right]) {
            ++result;
            --left;
            ++right;
        }
    }
public:
    Solution() {
        result = 0;
    }
    int countSubstrings(string s) {
        size = s.size();
        
        for(int i = 0;i < size;++i) {
            util(s,i,i);
            util(s,i,i+1);
        }
        
        return result;
    }
};