class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int profit = 0;
        int buyPrice = INT_MAX;
        for(auto x:prices) {
            buyPrice = min(buyPrice,x);
            profit = max(profit,x-buyPrice);
        }
        return profit;
    }
};
