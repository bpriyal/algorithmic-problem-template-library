class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t1Buy = INT_MIN, t1Sell = 0, t2Buy = INT_MIN, t2Sell = 0;
        int size = prices.size();
        for(int i=0;i<size;++i) {
            t1Buy = max(t1Buy,-prices[i]);
            t1Sell = max(t1Sell,t1Buy+prices[i]);
            t2Buy = max(t2Buy,t1Sell-prices[i]);
            t2Sell = max(t2Sell,t2Buy+prices[i]);
        }
        return t2Sell;
    }
};