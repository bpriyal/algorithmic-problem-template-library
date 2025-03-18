class LRUCache {
    std::list<pair<int, int>> lruCache;
    unordered_map<int, std::list<pair<int, int>>::iterator> idxMap;
    int capacity;
public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }
    
    int get(int key) {
      auto idxIt = idxMap.find(key);
      if (idxIt != idxMap.end()) {
        auto [_, value] = *idxIt->second;
        lruCache.erase(idxIt->second);
        lruCache.emplace_back(key, value);
        idxIt->second = std::prev(lruCache.end());
        return value;
      } else return -1;
    }
    
    void put(int key, int value) {
      auto idxIt = idxMap.find(key);
      if (idxIt != idxMap.end()) {
        lruCache.erase(idxIt->second);
      } else {
        if (lruCache.size() == capacity) {
          auto [k, v] = lruCache.front();
          lruCache.pop_front();
          idxMap.erase(k);
        }
      }
      lruCache.emplace_back(key, value);
      idxMap[key] = std::prev(lruCache.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */