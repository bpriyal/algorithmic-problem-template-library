class LRUCache {
public:
    list<int> lru;
    map<int,int> cache;
    int size;
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        lru.remove(key);
        lru.push_front(key);
        return cache[key];
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            if (lru.size() == size) {
                int last = lru.back();
                lru.pop_back();
                cache.erase(last);
            }
        } else {
            lru.remove(key);
        }
        cache[key] = value;
        lru.push_front(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */