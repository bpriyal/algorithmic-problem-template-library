class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int result = 0;
        int minBuy = prices[0];
        
        for(int i = 1;i < size;++i) {
            result = max(result, prices[i] - minBuy);
            minBuy = min(minBuy, prices[i]);
        }
        
        return result;
    }
};