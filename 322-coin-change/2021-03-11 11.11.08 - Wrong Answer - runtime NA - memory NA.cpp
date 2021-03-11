class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),[](const int &a,const int &b) {
            return a > b;
        });
        
        int result = 0;
        for(int i = 0;i < coins.size() && amount != 0;++i) {
            while (amount >= coins[i]) {
                amount -= coins[i];
                ++result;
            }
        }
        if (amount != 0) {
            return -1;
        }
        return result;
    }
};