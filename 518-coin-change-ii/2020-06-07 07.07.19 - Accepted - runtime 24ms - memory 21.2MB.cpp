class Solution {
public:
    vector<vector<int>> cache;
    int util(int amount,int coino,const vector<int>& coins) {
        if (amount == 0) return 1;
        if (amount < 0) return 0;
        if (coino < 0 && amount >= 1) {
            return 0;
        }
        if (cache[amount][coino] != -1) return cache[amount][coino];
        cache[amount][coino] = util(amount,coino-1,coins) + util(amount-coins[coino],coino,coins);
        return cache[amount][coino];
    }
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        cache.resize(amount+1);
        for(int i =0;i<=amount;++i) {
            cache[i].resize(m,-1);
        }
        return util(amount,m-1,coins);
    }
};