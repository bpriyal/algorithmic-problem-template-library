class MedianFinder {
    priority_queue<int, vector<int>> lo; // max heap
    priority_queue<int, vector<int>, greater<int>> hi; // min healp
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.emplace(num);
        if (lo.size() > 1) {
            int loMax = lo.top();
            lo.pop();
            hi.emplace(loMax);
            if (lo.size() < hi.size()) {
                int hiMin = hi.top();
                hi.pop();
                lo.emplace(hiMin);
            }
        }
    }
    
    double findMedian() {
        return lo.size() > hi.size()? lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */