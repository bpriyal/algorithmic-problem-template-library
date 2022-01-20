class Solution {
public:
    bool isPalindrome(int x) {
        string s = "";
        
        while (x != 0) {
            s += x%10;
            x /= 10;
        }
        
        int size = s.size();
        
        for (int i = 0; i < size/2; ++i) {
            if (s[i] != s[size-1-i]) {
                return false;
            }
        }
        
        return true;
    }
};