class Solution {
    int size;
    vector<int> dp;
    int util(const vector<int>& nums, int i, int run, int isLastUsed) {
        if (i == size) {
            return run;
        }
        
        if (dp[i] != -1) return dp[i];
        
        int res = INT_MIN;
        if (!isLastUsed) {
            res = max(res, util(nums, i + 1, run + nums[i], true));
        }
        
        res = max(res, util(nums, i + 1, run, false));
        dp[i] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {
        size = nums.size();
        dp.resize(size, -1);
        
        return util(nums, 0, 0, false);
    }
};