class Solution {
public:
    int strStr(string haystack, string needle) {
        int haySize = haystack.size();
        int needleSize = needle.size();
        
        if (needleSize == 0) {
            return 0;
        }
        
        int i = 0,j = 0;
        int pos = 0;
        
        while (i < haySize && j < needleSize) {
            if (haystack[i] == needle[j]) {
                ++j;
            } else if (j != 0) {
                j = 0;
            }
            ++i;
        }
        
        return j == needleSize? i-needleSize:-1;
    }
};