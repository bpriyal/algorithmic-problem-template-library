class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int count = 0;
        for(int i = size-1;i >= 0;--i) {
            if (s[i] == ' ') {
                return count;
            }
            ++count;
        }
        return count;
    }
};