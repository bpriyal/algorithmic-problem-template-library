class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // (t+1)^x = m;
        return ceil(log(buckets)/log(minutesToTest/minutesToDie+1));
    }
};