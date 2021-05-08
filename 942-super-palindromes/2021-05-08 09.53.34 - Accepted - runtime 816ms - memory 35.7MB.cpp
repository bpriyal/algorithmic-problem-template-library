class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        int result = 0;
        long l = stol(L);
        long r = stol(R);
        
        back_tracking("",l,r,result);
        
        for(int i = 0;i <= 9;++i) {
            back_tracking(string(1,'0'+i),l,r,result);
        }
        
        return result;
    }
    
    void back_tracking(const string &s,long l,long r,int &result) {
        if (s.size() > 9) {
            return;
        }
        
        if (!s.empty() && s[0] != '0') {
            long cur = stol(s);
            long cur2 = cur*cur;
            if (cur2 > r) {
                return;
            }
            
            if (cur2 >= l && is_palindrome(to_string(cur2))) {
                ++result;
            }
        }
        
        for(int i = 0;i <= 9;++i) {
            back_tracking(string(1,'0'+i)+s+string(1,'0'+i),l,r,result);
        }
    }
    
    bool is_palindrome(string s){
        int l = 0, r = s.size()-1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};