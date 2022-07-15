class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int result = 0;
        
        for(int i = 0;i < size - 1;++i) {
            for(int j = i + 1;j < size;++j) {
                if (prices[j] >= prices[i]) {
                    result = max(result, prices[j] - prices[i]);
                }
            }
        }
        
        return result;
    }
};