class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            char c1 = std::tolower(s[i]);
            char c2 = std::tolower(s[j]);
            if (!isalnum(c1)) ++i;
            else if (!isalnum(c2)) --j;
            else {
                if (c1 != c2) return false;
                ++i;
                --j;
            }
        }
        return true;
    }
};