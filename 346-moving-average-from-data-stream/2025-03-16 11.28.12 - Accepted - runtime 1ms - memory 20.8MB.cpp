class MovingAverage {
    queue<double> _q;
    int _capacity;
    double _sum = 0;
public:
    MovingAverage(int size) {
      _capacity = size;
    }
    
    double next(int val) {
      if (_q.size() == _capacity) {
        _sum -= _q.front();
        _q.pop();
      }
      double dval = static_cast<double>(val);
      _sum += dval;
      _q.emplace(dval);
      return _sum / _q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */