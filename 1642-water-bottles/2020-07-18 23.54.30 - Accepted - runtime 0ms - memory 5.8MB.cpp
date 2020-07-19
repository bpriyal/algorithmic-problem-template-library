class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = 0;
        int filled = numBottles;
        int empty = 0;
        while(filled > 0) {
            result += filled;
            empty = empty + filled;
            filled = empty/numExchange;
            empty = empty - filled*numExchange;
        }
        return result;
    }
};