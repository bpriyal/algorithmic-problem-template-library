class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int result = 1;
        
        while (!st.empty() && st.top().first <= price) {
            result += st.top().second;
            st.pop();
        }
        
        st.push(std::make_pair(price, result));
        
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */