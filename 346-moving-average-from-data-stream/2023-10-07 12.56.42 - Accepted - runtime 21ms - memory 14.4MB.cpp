class MovingAverage {
    int _capacity;
    queue<int> _q;
    double _movingSum;
public:
    MovingAverage(int size) {
        _capacity = size;
        _movingSum = 0.;
    }
    
    double next(int val) {
        if (_q.size() < _capacity) {
            _movingSum += val;
        } else {
            _movingSum += val - _q.front();
            _q.pop();
        }
        _q.emplace(val);
        return _movingSum/_q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */