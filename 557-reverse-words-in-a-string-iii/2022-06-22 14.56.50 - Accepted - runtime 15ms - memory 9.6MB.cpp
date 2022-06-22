class Solution {
    void reverseString(string& s, int l, int r) {
        for (int i = l;i <= (l+r)/2;++i) {
            int temp = s[i];
            s[i] = s[(l+r) - i];
            s[(l+r) - i] = temp;
        }
    }
public:
    string reverseWords(string s) {
        int l = 0;
        
        for(int i = 0;i < s.size();++i) {
            if (s[i] == ' ') {
                reverseString(s, l, i - 1);
                l = i + 1;
            }
        }
        
        reverseString(s, l, s.size() - 1);
        
        return s;
    }
};