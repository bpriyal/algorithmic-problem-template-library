class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> cache(52,0);
        int size = s.size();
        for(int i = 0;i<size;++i) {
            ++cache[s[i]-'A'];
        }
        int result = 0;
        bool oddEncountered = false;
        for(int i = 0;i<52;++i) {
            if (cache[i] % 2 == 0) {
                result += cache[i];
            } else {
                oddEncountered = true;
                result += cache[i]-1;
            }
        }
        return oddEncountered? result + 1 : result;
    }
};