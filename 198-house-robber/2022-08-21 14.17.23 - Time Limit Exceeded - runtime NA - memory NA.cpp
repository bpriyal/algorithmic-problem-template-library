class Solution {
    int size;
    // vector<vector<int>> dp;
    int util(const vector<int>& nums, int i, int run, bool isLastUsed) {
        if (i == size) {
            return run;
        }
        
        // if (dp[i][isLastUsed] != -1) return dp[i][isLastUsed];
        
        int res = INT_MIN;
        if (!isLastUsed) {
            res = max(res, util(nums, i + 1, run + nums[i], true));
        }
        
        res = max(res, util(nums, i + 1, run, false));
        // dp[i][isLastUsed] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {
        size = nums.size();
        // dp.resize(size, vector<int>(2, -1));
        
        return util(nums, 0, 0, false);
    }
};