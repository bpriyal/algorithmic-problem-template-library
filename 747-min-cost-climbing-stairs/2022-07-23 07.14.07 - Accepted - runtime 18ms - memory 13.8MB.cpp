class Solution {
    int size;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size = cost.size();
        vector<int> cache(size, 0);
        cache[0] = cost[0];
        cache[1] = cost[1];
        
        for(int i = 2; i < size; ++i) {
            cache[i] = cost[i] + min(cache[i-1], cache[i-2]);
        }
        
        return min(cache[size - 1], cache[size - 2]);
    }
};