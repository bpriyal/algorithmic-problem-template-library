class Solution {
    vector<vector<string>> result;
    int size;
    bool isPalindrome(string &s,int left,int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    
    void util(string &s,int pos,vector<string> cache) {
        if (pos == size) {
            result.push_back(cache);
        }
        for(int i = pos;i < size;++i) {
            if(isPalindrome(s,pos,i)) {
                cache.push_back(s.substr(pos,i-pos+1));
                util(s,i+1,cache);
                cache.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        size = s.size();
        vector<string> cache;
        util(s,0,cache);
        return result;
    }
};