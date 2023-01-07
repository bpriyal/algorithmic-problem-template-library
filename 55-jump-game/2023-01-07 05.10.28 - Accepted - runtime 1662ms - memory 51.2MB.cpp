class Solution {
    int size;
    vector<int> dp;
    bool util(const vector<int>& nums, int currPos) {
        if (currPos >= size - 1) return true;

        if (dp[currPos] != -1) return dp[currPos];

        for (int i = 1; i <= nums[currPos]; ++i) {
            if (util(nums, currPos + i)) {
                dp[currPos] = 1;
                return true;
            }
        }
        dp[currPos] = 0;
        return dp[currPos];
    }
public:
    bool canJump(vector<int>& nums) {
        size = nums.size();
        dp.resize(size, -1);
        return util(nums, 0);
    }
};