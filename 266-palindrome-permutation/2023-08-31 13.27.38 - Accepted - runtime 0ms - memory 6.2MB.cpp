class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> cache(26, 0);
        for (auto c : s) ++cache[c - 'a'];
        int numberOfOddFrequencies = 0;
        for (auto frequency : cache) {
            if (frequency % 2 != 0) {
                ++numberOfOddFrequencies;
                if (numberOfOddFrequencies > 1) return false;
            }
        }
        return true;
    }
};