class Solution {
    int size;
    int sum;
    vector<bool> dp;
//     bool util(vector<int>& nums, int set1, int i) {
//         if (set1 == sum/2) return true;
//         if (set1 > sum/2 || i >= size) return false;
        
//         if (dp[i][set1] != -1) return dp[i][set1];
        
//         dp[i][set1] = util(nums, set1 + nums[i], i + 1) || util(nums, set1, i + 1);
        
//         return dp[i][set1];
//     }
public:
    bool canPartition(vector<int>& nums) {
        size = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2 != 0) return false;
        
        dp.resize(sum/2 + 1, false);
        dp[0] = true;
        
        for(int i = 1; i <= size; ++i) {
            for(int j = 1; j <= sum/2; ++j) {
                dp[j] = dp[j];
                
                if (j - nums[i-1] >= 0) dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        
        return dp[sum/2];
    }
};