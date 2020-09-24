class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cache(26,0);
        for(auto x:s) {
            ++cache[x-'a'];
        }
        for(auto x:t) {
            if (cache[x-'a'] != 1) {
                return x;
            }
        }
        return 0;
    }
};