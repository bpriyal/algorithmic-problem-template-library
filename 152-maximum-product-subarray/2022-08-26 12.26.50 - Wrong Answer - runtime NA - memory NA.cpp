class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        
        for(int i = 1; i < size; ++i) {
            dp[i] = max(nums[i], dp[i-1] * nums[i]);
        }
        
        int result = INT_MIN;
        for(auto num : dp) {
            result = max(result, num);
        }
        return result;
    }
};