class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;

        for (int i = 0; i < nums.size(); ++i) {
            if (cache.find(target - nums[i]) != cache.end()) return vector<int>({cache[target - nums[i]], i});
            cache.emplace(nums[i], i);
        }

        return vector<int>();
    }
};