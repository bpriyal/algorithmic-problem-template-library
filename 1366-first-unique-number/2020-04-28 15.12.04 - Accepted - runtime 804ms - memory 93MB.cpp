class FirstUnique {
public:
    list<int> queue;
    map<int,list<int>::iterator> hashmap;
    FirstUnique(vector<int>& nums) {
        for (auto i:nums) {
            add(i);
        }
    }
    
    int showFirstUnique() {
        if (queue.size() == 0) return -1;
        return queue.front();
    }
    
    void add(int value) {
        if (hashmap.find(value) == hashmap.end()) {
            queue.push_back(value);
            list<int>::iterator it = queue.end();
            it--;
            hashmap[value] = it;
        } else {
            if (hashmap[value] != queue.end()) {
                queue.erase(hashmap[value]);
                hashmap[value] = queue.end();
            }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */