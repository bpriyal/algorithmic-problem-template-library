class KthLargest {
    priority_queue<int, vector<int>, greater<int>> cache;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for (int num : nums) {
            cache.emplace(num);

            if (cache.size() > k) cache.pop();
        }
    }
    
    int add(int val) {
        cache.emplace(val);

        if (cache.size() > n) cache.pop();

        return cache.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */ 