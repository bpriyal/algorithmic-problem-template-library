class Solution {
    int size;
    int util(const vector<int>& coins, int i, int amount) {
        if (amount == 0) return 0;
        if (amount < 0 || i >= size) return INT_MAX;
                
        if (coins[i] > amount) return INT_MAX;
        
        int useCoin = util(coins, i, amount - coins[i]);
        int dontUseCoin = util(coins, i + 1, amount);
        
        return min(useCoin == INT_MAX? INT_MAX : useCoin + 1, dontUseCoin);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        size = coins.size();
        
        sort(coins.begin(), coins.end());
        
        int result = util(coins, 0, amount);
        
        return result == INT_MAX? -1 : result;
    }
};