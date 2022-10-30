class StockSpanner {
    vector<int> cache;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        cache.push_back(price);
        
        int result = 0;
        for (int i = cache.size() - 1; i >= 0; --i) {
            if (cache[i] <= price) ++result;
            else return result;
        }
        
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */