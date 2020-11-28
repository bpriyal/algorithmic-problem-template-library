class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        
        int sum = 0;
        for(int num:nums) {
            sum += num;
        }
        
        if ((sum & 1) == 1) {
            return false;
        }
        
        sum /= 2;
        
        vector<vector<bool>> dp(size+1,vector<bool>(sum+1,false));
        
        for(int i = 0;i <= size;++i) {
            dp[i][0] = true;
        }
        
        for(int i = 1;i <= size; ++i) {
            for(int j = 1;j <= sum;++j) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[size][sum];
    }
};