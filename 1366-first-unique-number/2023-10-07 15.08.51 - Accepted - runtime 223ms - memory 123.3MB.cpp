class FirstUnique {
    queue<int> queue;
    unordered_map<int, int> hashmap; // key to frequency
public:
    FirstUnique(vector<int>& nums) {
        for (const auto& num : nums) {
            queue.emplace(num);
            ++hashmap[num];
        }
    }
    
    int showFirstUnique() {
        while (!queue.empty() && hashmap[queue.front()] > 1) queue.pop();
        return queue.empty()? -1 : queue.front();
    }
    
    void add(int value) {
        queue.emplace(value);
        ++hashmap[value];
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */