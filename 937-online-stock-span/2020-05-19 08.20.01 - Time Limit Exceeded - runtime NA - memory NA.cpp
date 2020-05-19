class StockSpanner {
public:
    vector<int> prices;
    int size;
    StockSpanner() {
        size = 0;
    }
    
    int next(int price) {
        cout<<size<<endl;
        if (size == 0) {
            prices.push_back(price);
            ++size;
            return 1;
        }
        int count = 1;
        for (int i=size-1;i>=0;--i) {
            if (prices[i] > price) break;
            else ++count;
        }
        prices.push_back(price);
        ++size;
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */