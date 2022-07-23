class Solution {
    int size;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size = cost.size();
        // vector<int> cache(size, 0);
        // cache[0] = cost[0];
        // cache[1] = cost[1];
        
        int a = cost[0];
        int b = cost[1];
        
        for(int i = 2; i < size; ++i) {
            // cache[i] = cost[i] + min(cache[i-1], cache[i-2]);
            int temp = cost[i] + min(a, b);
            a = b;
            b = temp;
        }
        
        return min(a, b);
    }
};