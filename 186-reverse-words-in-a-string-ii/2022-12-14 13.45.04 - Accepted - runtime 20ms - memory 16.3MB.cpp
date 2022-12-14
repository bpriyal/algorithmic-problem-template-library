class Solution {
public:
    void reverseWords(vector<char>& s) {
        int size = s.size();
        
        reverse(s.begin(), s.end());

        int start = 0;
        int end = start;
        while (start < size) {
            while (end < size && s[end] != ' ') ++end;
            reverse(s.begin() + start, s.begin() + end);
            ++end;
            start = end;
        }
    }
};