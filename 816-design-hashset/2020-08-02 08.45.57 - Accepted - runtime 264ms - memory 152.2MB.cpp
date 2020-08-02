class MyHashSet {
    vector<list<int>> buckets;
    int bucketSize;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        bucketSize = 150000;
        buckets.resize(bucketSize);
    }
    
    void add(int key) {
        int position = key%bucketSize;
        buckets[position].push_back(key);
    }
    
    void remove(int key) {
        int position = key%bucketSize;
        buckets[position].remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int position = key%bucketSize;
        auto it = find(buckets[position].begin(),buckets[position].end(),key);
        if (it == buckets[position].end()) {
            return false;
        } else {
            return true;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */