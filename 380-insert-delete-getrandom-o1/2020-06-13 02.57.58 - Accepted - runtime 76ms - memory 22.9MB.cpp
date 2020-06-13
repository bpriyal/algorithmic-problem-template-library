class RandomizedSet {
public:
    unordered_map<int,int> cache;
    vector<int> elements;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(cache.find(val) == cache.end()) {
            elements.push_back(val);
            cache[val] = elements.size() - 1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(cache.find(val) != cache.end()) {
            swap(elements[elements.size()-1],elements[cache[val]]);
            elements.pop_back();
            cache[elements[cache[val]]] = cache[val];
            cache.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return elements[rand()%elements.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */