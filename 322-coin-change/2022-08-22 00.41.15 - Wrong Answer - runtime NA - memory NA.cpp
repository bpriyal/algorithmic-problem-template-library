class Solution {
    int size;
    vector<int> dp;
    int util(vector<int>& coins, int amount, int run) {
        if (amount == 0) return run;
        if (amount < 0) return INT_MAX;
        
        if (dp[amount] != -1) return dp[amount];
        
        int res = INT_MAX;
        
        for(int i = size - 1; i >= 0; --i) {
            if (coins[i] <= amount) {
                res = min(res, util(coins,amount - coins[i], run + 1));   
            }
        }
        
        dp[amount] = res;
        
        return res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        size = coins.size();
        dp.resize(amount + 1, -1);
        
        int result = util(coins, amount, 0);
        
        return result == INT_MAX? -1 : result;
    }
};