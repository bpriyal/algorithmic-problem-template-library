class Solution {
    int size;
    vector<int> dp;
    int util(vector<int> &cost,int i,int run) {
        if (i >= size) {
            return run;
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }
        
        // climb 2 steps
        int result = util(cost,i+2,run+cost[i]);
        result = min(result,util(cost,i+1,run+cost[i]));
        dp[i] = result;
        return result;
    } 
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size = cost.size();
        
        /*dp.resize(size,-1);
        int result = util(cost,0,0);
        dp = {};
        
        dp.resize(size,-1);
        result = min(result,util(cost,1,0));
        
        return result;*/
        
        dp.resize(size,0);
        dp[size-1] = cost[size-1];
        dp[size-2] = cost[size-2];
        
        for(int i = size - 3;i >= 0;--i) {
            dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
        }
        
        return min(dp[0],dp[1]);
    }
};