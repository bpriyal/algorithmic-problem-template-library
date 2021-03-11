class Solution {
    int _min;
    void util(const vector<int> &coins,int amount,int i,int run) {
        if (i >= coins.size()) {
            return;
        }
        if (amount == 0) {
            _min = min(_min,run);
            return;
        }
        if (coins[i] <= amount) {
            util(coins,amount-coins[i],i,run+1);
            util(coins,amount,i+1,run);
        } else {
            util(coins,amount,i+1,run);
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(begin(coins),end(coins),[](const int &a,const int &b) {
            return a > b;
        });
        /*_min = INT_MAX;
        util(coins,amount,0,0);
        return _min == INT_MAX? -1 : _min;*/
        
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        
        for(int i = 1;i <= amount;++i) {
            //printf("i:%d\n",i);
            for(int j = 0;j < coins.size();++j) {
                if (i - coins[j] >= 0 && dp[i-coins[j]] != -1) {
                    if (dp[i] == -1) {
                        dp[i] = dp[i-coins[j]] + 1;
                        continue;
                    }
                    dp[i] = min(dp[i],dp[i-coins[j]] + 1);
                    //printf("coin used for i:%d =%d has value :%d\n",i,coins[j],dp[i]);
                    break;
                }
            }
        }
        
        /*for(int i = 0;i <= amount;++i) {
            cout<<dp[i]<<"\t";
        }*/
        
        return dp[amount];
    }
};