class KthLargest {
    priority_queue<int> cache;
    int n;
    vector<int> sortedLargestList;

    void sortArray(vector<int>& sortedLargestList, int val) {
        int i = 0;
        for (i = 0; i < n; ++i) {
            if (val > sortedLargestList[i]) break;
        }

        int prev = sortedLargestList[i];
        for (int j = i + 1; j < n; ++j) {
            int temp = sortedLargestList[j];
            sortedLargestList[j] = prev;
            prev = temp;
        }
        sortedLargestList[i] = val;
    }

public:
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) cache.emplace(num);
        n = k;

        for (int i = 0; i < min(n, static_cast<int>(nums.size())); ++i) {
            sortedLargestList.emplace_back(cache.top());
            cache.pop();
        }
        for (int num : sortedLargestList) cache.emplace(num);
    }
    
    int add(int val) {
        cache.emplace(val);

        if (sortedLargestList.size() < n) {
            sortedLargestList.resize(n);
            for (int i = 0; i < n; ++i) {
                sortedLargestList[i] = cache.top();
                cache.pop();
            }
            for (int num : sortedLargestList) cache.emplace(num);

            return sortedLargestList.back();
        }

        if (sortedLargestList.back() < val) sortArray(sortedLargestList, val);
        return sortedLargestList.back();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */