class LRUCache {
    std::list<pair<int, int>> _list;
    unordered_map<int, std::list<pair<int, int>>::iterator> _cache;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (auto it = _cache.find(key); it != _cache.end()) {
            auto [k, v] = *(it->second);
            _list.erase(it->second);
            _cache.erase(key);
            _list.push_back({k, v});
            _cache.emplace(k, --(_list.end()));
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (auto it = _cache.find(key); it != _cache.end()) {
            _list.erase(it->second);
            _cache.erase(key);
        } else if (_list.size() >= _capacity) {
            auto [k, v] = _list.front();
            _list.pop_front();
            _cache.erase(k);
        }
        _list.push_back({key, value});
        _cache.emplace(key, --(_list.end()));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */