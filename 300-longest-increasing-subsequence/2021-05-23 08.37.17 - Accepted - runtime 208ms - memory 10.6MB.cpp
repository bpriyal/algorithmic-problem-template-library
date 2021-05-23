class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,0);
        dp[0] = 1;
        int result = 1;
        for(int i = 1;i < size;++i) {
            int _max = 0;
            for(int j = 0;j < i;++j) {
                if (nums[i] > nums[j]) {
                    _max = max(_max,dp[j]);
                }
            }
            dp[i] = _max+1;
            result = max(result,dp[i]);
        }
        return result;
    }
};