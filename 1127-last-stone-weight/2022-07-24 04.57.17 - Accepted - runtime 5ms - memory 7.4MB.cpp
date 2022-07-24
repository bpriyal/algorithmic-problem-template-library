class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int size = stones.size();
        
        std::priority_queue<int> cache;
        
        for(const int &stone : stones) {
            cache.push(stone);
        }
        
        while(cache.size() > 1) {
            int w1 = cache.top();
            cache.pop();
            
            int w2 = cache.top();
            cache.pop();
            
            if (w1 != w2) cache.push(abs(w1-w2));
        }
        
        return cache.empty()? 0 : cache.top();
    }
};