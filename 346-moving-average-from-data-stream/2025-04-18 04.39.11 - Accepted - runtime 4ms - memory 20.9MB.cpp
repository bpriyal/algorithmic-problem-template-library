class MovingAverage {
    int _size;
    queue<int> q;
    double runSum = 0;
public:
    MovingAverage(int size) {
      _size = size;
    }
    
    double next(int val) {
      if (q.size() >= _size) {
        runSum -= q.front();
        q.pop();
      }
      q.emplace(val);
      runSum += val;
      return runSum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */