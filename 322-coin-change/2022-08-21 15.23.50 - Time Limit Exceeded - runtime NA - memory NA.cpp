class Solution {
    int size;
    int util(vector<int>& coins, int amount, int run) {
        if (amount == 0) return run;
        if (amount < 0) return INT_MAX;
        
        int res = INT_MAX;
        
        for(int i = size - 1; i >= 0; --i) {
            if (coins[i] <= amount) {
                res = min(res, util(coins,amount - coins[i], run + 1));   
            }
        }
        
        return res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        size = coins.size();
        
        int result = util(coins, amount, 0);
        
        return result == INT_MAX? -1 : result;
    }
};