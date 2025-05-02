class LRUCache {
    std::list<pair<int, int>> lru;
    unordered_map<int, std::list<pair<int, int>>::iterator> map;
    int _capacity;
public:
    LRUCache(int capacity) {
      _capacity = capacity;
    }
    
    int get(int key) {
      auto it = map.find(key);
      if (it != map.end()) {
        auto [k, v] = *it->second;
        lru.erase(it->second);
        lru.emplace_back(make_pair(key, v));
        map[key] = std::prev(lru.end());
        return v;
      }
      return -1;
    }
    
    void put(int key, int value) {
      auto it = map.find(key);
      if (it != map.end()) {
        lru.erase(it->second);
      }
      if (map.size() >= _capacity) {
        auto [k, v] = lru.front();
        lru.pop_front();
        map.erase(k);
      }
      lru.emplace_back(make_pair(key, value));
      map[key] = std::prev(lru.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */