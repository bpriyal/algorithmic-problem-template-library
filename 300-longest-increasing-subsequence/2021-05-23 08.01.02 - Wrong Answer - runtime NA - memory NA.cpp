class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,0);
        dp[0] = 1;
        
        for(int i = 1;i < size;++i) {
            dp[i] = nums[i] > nums[i-1] ? dp[i-1]+1:dp[i-1];
        }
        
        return dp[size-1];
    }
};