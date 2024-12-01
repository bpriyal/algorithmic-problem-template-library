class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIdxMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) numToIdxMap.emplace(nums[i], i);
        for (int i = 0; i < nums.size(); ++i) {
            if (auto it = numToIdxMap.find(target - nums[i]); it != numToIdxMap.end() && i != it->second) {
                result.emplace_back(i);
                result.emplace_back(it->second);
                return result;
            }
        }
        return result;
    }
};