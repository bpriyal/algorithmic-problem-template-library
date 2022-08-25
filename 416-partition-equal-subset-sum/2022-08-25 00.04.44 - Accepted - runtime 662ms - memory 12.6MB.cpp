class Solution {
    int size;
    int sum;
    vector<vector<bool>> dp;
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
        
        dp.resize(size + 1, vector<bool>(sum/2 + 1, -1));
        for(int i = 0;i <= size; ++i) dp[i][0] = true;
        for(int i = 1; i <= sum/2; ++i) dp[0][i] = false;
        
        for(int i = 1; i <= size; ++i) {
            for(int j = 1; j <= sum/2; ++j) {
                dp[i][j] = dp[i-1][j];
                
                if (j - nums[i-1] >= 0) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[size][sum/2];
    }
};