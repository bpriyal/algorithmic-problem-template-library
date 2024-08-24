class ZigzagIterator {
    vector<vector<int>> _cache;
    std::queue<std::pair<int, int>> _itQ;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        _cache.emplace_back(v1);
        _cache.emplace_back(v2);
        for (int i = 0; i < _cache.size(); ++i) {
          if (!_cache[i].empty()) _itQ.emplace(i, 0);
        }
    }

    int next() {
      auto [vectorNumber, idx] = _itQ.front();
      auto result = _cache[vectorNumber][idx++];
      _itQ.pop();
      if (_cache[vectorNumber].size() > idx) _itQ.emplace(vectorNumber, idx);
      return result;
    }

    bool hasNext() {
      return !_itQ.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */