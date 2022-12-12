class MovingAverage {
    queue<int> cache;
    double sum;
    int capacity, currentSize;
public:
    MovingAverage(int size) {
        capacity = size;
        currentSize = 0;
        sum = 0.;
    }
    
    double next(int val) {
        if (currentSize < capacity) {
            cache.emplace(val);
            ++currentSize;
            sum += val;
            return sum/currentSize;
        }

        sum +=  val - cache.front();
        
        cache.pop();
        cache.emplace(val);

        return sum/capacity;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */