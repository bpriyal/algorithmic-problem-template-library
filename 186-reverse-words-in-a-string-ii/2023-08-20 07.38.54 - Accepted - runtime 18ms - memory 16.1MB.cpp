class Solution {
public:
    void reverseWords(vector<char>& s) {
        int size = s.size();
        reverse(s.begin(), s.end());
        
        int lastSpaceIdx = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + lastSpaceIdx, s.begin() + i);
                lastSpaceIdx = i + 1;
            }
        }
        reverse(s.begin() + lastSpaceIdx, s.end());
    }
};