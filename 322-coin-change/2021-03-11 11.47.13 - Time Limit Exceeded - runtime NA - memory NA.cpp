class Solution {
    int _min;
    void util(const vector<int> &coins,int amount,int i,int run) {
        if (i >= coins.size()) {
            return;
        }
        if (amount == 0) {
            //printf("run:%d\n",run);
            _min = min(_min,run);
            return;
        }
        if (coins[i] <= amount) {
            //cout<<amount-coins[i]<<endl;
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
        _min = INT_MAX;
        util(coins,amount,0,0);
        return _min == INT_MAX? -1 : _min;
    }
};