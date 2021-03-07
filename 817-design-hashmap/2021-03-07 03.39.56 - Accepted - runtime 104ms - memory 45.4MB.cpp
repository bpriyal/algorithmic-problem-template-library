class MyHashMap {
    vector<list<pair<int,int>>> cache;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        cache.resize(100);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash = key%100;
        for(auto &x:cache[hash]) {
            if (x.first == key) {
                x.second = value;
                return;
            }
        }
        cache[hash].push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash = key%100;
        for(const auto &x:cache[hash]) {
            if (x.first == key) {
                return x.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash = key%100;
        for(list<pair<int,int>>::iterator it = cache[hash].begin(); it != cache[hash].end();++it) {
            if (it->first == key) {
                cache[hash].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */