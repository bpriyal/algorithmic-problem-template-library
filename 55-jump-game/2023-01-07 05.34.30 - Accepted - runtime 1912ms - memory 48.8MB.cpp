class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<bool> dp(size, 0);

        dp[size - 1] = true;

        for (int i = size - 2; i >= 0; --i) {
            for (int jump = 1; jump <= nums[i] && i + jump < size ; ++jump) {
                dp[i] = dp[i + jump];
                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};