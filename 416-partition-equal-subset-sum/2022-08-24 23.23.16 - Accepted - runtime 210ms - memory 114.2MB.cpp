class Solution {
    int size;
    int sum;
    vector<vector<int>> dp;
    bool util(vector<int>& nums, int set1, int i) {
        if (set1 == sum/2) return true;
        if (set1 > sum/2 || i >= size) return false;
        
        if (dp[i][set1] != -1) return dp[i][set1];
        
        dp[i][set1] = util(nums, set1 + nums[i], i + 1) || util(nums, set1, i + 1);
        
        return dp[i][set1];
    }
public:
    bool canPartition(vector<int>& nums) {
        size = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        
        dp.resize(size, vector<int>(sum/2, -1));
        
        if (sum%2 != 0) return false;
        
        return util(nums, 0, 0);
    }
};