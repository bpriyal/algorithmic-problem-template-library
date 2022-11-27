class KthLargest {
    priority_queue<int> cache;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) cache.emplace(num);
        n = k;
    }
    
    int add(int val) {
        cache.emplace(val);

        vector<int> temp(n);
        for (int i = 0; i < n; ++i) {
            cout<<cache.top()<<endl;
            temp[i] = cache.top();
            cache.pop();
        }
        for (int num : temp) cache.emplace(num);

        return temp[n - 1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */