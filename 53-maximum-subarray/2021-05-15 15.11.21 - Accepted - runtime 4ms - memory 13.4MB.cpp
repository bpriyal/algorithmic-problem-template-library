class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,0);
        int result = nums[0];
        dp[0] = nums[0];
        
        for(int i = 1;i < size;++i) {
            dp[i] = nums[i]+(dp[i-1] > 0? dp[i-1]:0);
            result = max(result,dp[i]);
        }
        
        return result;
    }
};