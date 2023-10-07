class FirstUnique {
    list<int> queue;
    map<int, list<int>::iterator> hashmap;
public:
    FirstUnique(vector<int>& nums) {
        for (const auto& num : nums) add(num);
    }
    
    int showFirstUnique() {
        return queue.empty() ? -1 : queue.front();
    }
    
    void add(int value) {
        if (hashmap.find(value) == hashmap.end()) {
            queue.emplace_back(value);
            auto it = queue.end();
            --it;
            hashmap.try_emplace(value, --queue.end());
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