class BrowserHistory {
    vector<string> cache;
    int current;
public:
    BrowserHistory(string homepage) {    
        cache.push_back(homepage);
        current = 0;
    }
    
    void visit(string url) {
        cache.erase(cache.begin()+current+1,cache.end());
        cache.push_back(url);
        ++current;
    }
    
    string back(int steps) {
        if (steps < current) {
            current = current - steps;
            return cache[current];
        }
        current = 0;
        return cache[0];
    }
    
    string forward(int steps) {
        if (steps < cache.size() - current) {
            current = current + steps;
            return cache[current];
        }
        current = cache.size() - 1;
        return cache[current];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */