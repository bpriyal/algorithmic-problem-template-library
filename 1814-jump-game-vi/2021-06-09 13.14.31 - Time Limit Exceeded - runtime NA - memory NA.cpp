class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> dp(size,0);
        
        for(int i = size-1;i >= 0;--i) {
            dp[i] = nums[i];
            int _max = INT_MIN;
            for(int j = i+1;j <= min(size-1,i+k);++j) {
                _max = max(_max,dp[j]);
            }
            
            dp[i] += _max==INT_MIN? 0:_max;
        }
        
        /*for(int x:dp) {
            cout<<x<<"\t";
        }*/
        
        return dp[0];
    }
};