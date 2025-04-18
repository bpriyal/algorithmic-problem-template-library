class LRUCache {
    int _capacity;
    std::list<pair<int, int>> lru;
    unordered_map<int, std::list<pair<int, int>>::iterator> keyToPosMap;
public:
    LRUCache(int capacity) {
      _capacity = capacity; 
    }
    
    int get(int key) {
      auto it = keyToPosMap.find(key);
      if (it != keyToPosMap.end()) {
        auto [k, v] = *it->second;
        lru.erase(it->second);
        lru.emplace_back(make_pair(key, v));
        keyToPosMap[key] = std::prev(lru.end());
        return it->second->second;
      }
      return -1; 
    }
    
    void put(int key, int value) {
      auto it = keyToPosMap.find(key);
      if (it != keyToPosMap.end()) {
        lru.erase(it->second);
        keyToPosMap.erase(key); 
      } else {
        if (lru.size() == _capacity) {
          auto [k, v] = lru.front();
          lru.erase(lru.begin());
          keyToPosMap.erase(k);
        }
      }
      lru.emplace_back(make_pair(key, value));
      keyToPosMap.try_emplace(key, std::prev(lru.end()));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */