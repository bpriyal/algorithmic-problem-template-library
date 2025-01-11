class MedianFinder {
    vector<int> _cache;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (_cache.empty()) _cache.emplace_back(num);
        else _cache.insert(lower_bound(_cache.begin(), _cache.end(), num), num); // O(logn) + O(n)
    }
    
    double findMedian() {
        int size = _cache.size();
        return (size % 2)? _cache[size / 2] : (_cache[size / 2 - 1] + _cache[size / 2]) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */