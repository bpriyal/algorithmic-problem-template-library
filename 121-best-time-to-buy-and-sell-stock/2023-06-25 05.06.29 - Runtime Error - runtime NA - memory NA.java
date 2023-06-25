class Solution {
    public int maxProfit(int[] prices) {
        
        int max = prices[1];
        int maxI = 1;

        for (int i = 1; i < prices.length; ++i) {
            if (prices[i] > max) {
                max = prices[i];
                maxI = i;
            }
        }
       
       int min = prices[0];
       int minI = 0;
       for (int i = 0; i < maxI; ++i) {
           if (prices[i] < min) {
               min = prices[i];
               minI = i;
           }
       }
       int ret;
       return ret = max - min > 0 ? max - min : 0;

    }
}