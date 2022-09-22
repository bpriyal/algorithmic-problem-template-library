class Solution {
    void reverseWord(string& s, int start, int end) {
        while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            ++start;
            --end;
        }
    }
public:
    string reverseWords(string s) {
        int size = s.size();
        int start = 0;
        
        for (int i = 0; i < size; ++i) {
            if (s[i] == ' ') {
                reverseWord(s, start, i - 1);
                start = i + 1;
            }
        }
        
        reverseWord(s, start, size - 1);
        
        return s;
    }
};