class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<bool> dp(size, 0);

        dp[size - 1] = 1;

        for (int i = size - 2; i >= 0; --i) {
            for (int jump = 1; jump <= nums[i]; ++jump) {
                int dest = i + jump;
                if (dest >= size -1 ) dp[i] = true;
                else dp[i] = dp[dest];

                if (dp[i]) break;
            }
        }

        return dp[0];
    }
};