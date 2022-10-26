class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        
        unordered_map<int, int> cache;
        cache[0] = -1;
        int sum = 0;
        
        for (int i = 0; i < size; ++i) {
            sum = (sum + nums[i]) % k;
            
            if (cache.find(sum) != cache.end()) {
                if (i - cache[sum] > 1) return true;
            } else {
                cache[sum] = i;
            }
        }
        
        return false;
    }
};

// Time - O(n)
// Space - O(k)