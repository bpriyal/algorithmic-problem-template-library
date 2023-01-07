class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, INT_MAX);
        dp[size - 1] = 0;

        for (int i = size - 2; i >= 0; --i) {
            for (int jump = 1; jump <= nums[i] && i + jump < size; ++jump) {
                if (dp[i + jump] == INT_MAX) continue;
                dp[i] = min(dp[i], dp[i + jump] + 1);
            }
        }

        return dp[0];
    }
};