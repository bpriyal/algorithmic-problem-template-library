class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cache;
        int result = 0;
        bool oddFound = false;
        
        for(char &c: s) {
            if (cache.find(c) == cache.end()) cache[c] = 1;
            else ++cache[c];
        }
        
        for(auto it = cache.begin();it != cache.end();++it) {
            if (it->second%2 != 0) oddFound = true;
            result = result + it->second/2;
        }
        
        return result*2 + oddFound;
    }
};