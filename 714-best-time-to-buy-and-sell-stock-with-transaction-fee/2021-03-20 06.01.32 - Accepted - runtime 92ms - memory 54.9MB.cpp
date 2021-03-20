class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0; // holding no stock
        int hold = -prices[0]; // holding a stock
        
        for(int i = 1;i < prices.size();++i) {
            cash = max(cash,hold+prices[i]-fee); // sell stock
            hold = max(hold,cash-prices[i]); //buy stock
        }
        
        return cash;
    }
};