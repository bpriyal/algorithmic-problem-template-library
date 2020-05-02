class Solution {
public:
    map<char,int> cache;
    int numJewelsInStones(string J, string S) {
        int size = S.size();
        if (size == 0 || J.size() == 0) {
            return 0;
        }
        int count = 0;
        for (auto c : J) {
            cache[c] = 1;
        }
        for (auto c : S) {
            if (cache.find(c) != cache.end()) {
                ++count;
            }
        }
        return count;
    }
};