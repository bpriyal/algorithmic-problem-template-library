class LRUCache {
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int size;
    int capacity;
public:
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (auto cit = cache.find(key); cit != cache.end()) {
            int val = cit->second->second;
            lru.splice(lru.begin(), lru, cit->second);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (auto cit = cache.find(key); cit != cache.end()) {
            lru.splice(lru.begin(), lru, cit->second);
            cit->second->second = value;
            return;
        } else {
            if (size == capacity) {
                cache.erase(lru.back().first);
                lru.pop_back();
            } else {
                ++size;
            }
        }
        
        lru.emplace_front(std::make_pair(key, value));
        cache[key] = lru.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */