class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int size = prices.size();
      int minPrice = prices[0];
      int maxProfitPossible = INT_MIN;
      for (int price : prices) {
        maxProfitPossible = max(maxProfitPossible, price - minPrice);
        minPrice = min(minPrice, price); 
      }
      return maxProfitPossible;
    }
};