class StockSpanner {
public:
    // Solution 1: TLE
    /*vector<int> prices;
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
    }*/
    stack<int> price_index;
    vector<int> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (prices.size() == 0) {
            price_index.push(0);
            prices.push_back(price);
            return 1;
        }
        prices.push_back(price);
        int top = price_index.top();
        while (prices[top] <= price) {
            price_index.pop();
            if (price_index.empty()) {
                top = -1;
                break;
            }
            top = price_index.top();
        }
        price_index.push(prices.size()-1);
        return prices.size()-1-top;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */