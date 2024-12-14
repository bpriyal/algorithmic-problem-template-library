class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> cache;
        int runSum = 0, count = 0;
        cache[0] = 1;
        for (int num : nums) {
            runSum += num;
            ++cache[runSum];
            if (auto it = cache.find(runSum - k); it != cache.end()) count += it->second;
        }
        return count;
    }
};