class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int result = 0;
        int minBuy = prices[0];
        
        // for(int i = 0;i < size - 1;++i) {
        //     for(int j = i + 1;j < size;++j) {
        //         if (prices[j] >= prices[i]) {
        //             result = max(result, prices[j] - prices[i]);
        //         }
        //     }
        // }
        
        for(int i = 1;i < size;++i) {
            if (prices[i] > minBuy) {
                result = max(result, prices[i] - minBuy);
            } else {
                minBuy = min(minBuy, prices[i]);
            }
            
        }
        
        return result;
    }
};