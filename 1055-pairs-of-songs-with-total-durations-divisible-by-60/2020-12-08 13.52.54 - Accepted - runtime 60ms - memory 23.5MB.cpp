class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cache(60,0);
        int result = 0;
        for(int t:time) {
            result += cache[(60-t%60)%60];
            ++cache[t%60];
        }
        return result;
    }
};