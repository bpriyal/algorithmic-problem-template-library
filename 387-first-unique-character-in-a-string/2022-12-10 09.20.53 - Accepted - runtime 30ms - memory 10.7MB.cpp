class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cache(26, 0);

        for (int i = 0; i < s.size(); ++i) {
            ++cache[s[i] - 'a'];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (cache[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};