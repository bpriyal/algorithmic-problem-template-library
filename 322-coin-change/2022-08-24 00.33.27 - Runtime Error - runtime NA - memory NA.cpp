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
//         size = coins.size();
//         dp.resize(amount + 1, -1);
        
//         sort(coins.begin(), coins.end());
        
//         int result = util(coins, amount, 0);
        
//         return result == INT_MAX? -1 : result;
        
        vector<int> cache(amount+1, INT_MAX);
        cache[0] = 0;
        
        sort(coins.begin(), coins.end());
        
        for(int i = 1; i <= amount; ++i) {
            for(auto coin : coins) {
                if (i - coin < 0) break;
                cache[i] = min(cache[i], cache[i - coin] + 1);
            }
        }
        
        return cache[amount] == INT_MAX? -1 : cache[amount];
    }
};