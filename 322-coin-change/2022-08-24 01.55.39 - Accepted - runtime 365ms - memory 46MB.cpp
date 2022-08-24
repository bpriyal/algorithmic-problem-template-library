class Solution {
    int size;
    vector<vector<int>> dp;
    int util(const vector<int>& coins, int i, int amount) {
        if (amount == 0) return 0;
        if (amount < 0 || i >= size) return INT_MAX;
        
        if (dp[i][amount] != -1) return dp[i][amount];
        
        if (coins[i] > amount) return INT_MAX;
        
        int useCoin = util(coins, i, amount - coins[i]);
        int dontUseCoin = util(coins, i + 1, amount);
        
        dp[i][amount] = min(useCoin == INT_MAX? INT_MAX : useCoin + 1, dontUseCoin);
        
        return dp[i][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        size = coins.size();
        dp.resize(size, vector<int>(amount + 1, -1));
        
        sort(coins.begin(), coins.end());
        
        int result = util(coins, 0, amount);
        
        return result == INT_MAX? -1 : result;
    }
};