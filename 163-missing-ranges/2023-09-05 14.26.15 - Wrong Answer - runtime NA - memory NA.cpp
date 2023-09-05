class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        vector<vector<int>> result;
        if (size == 0) {
            result.emplace_back(vector<int>{lower, upper});
            return result;
        }

        // Between Lower and first num of nums
        if (nums.front() - lower > 1) result.emplace_back(vector<int>{lower, nums.front() - 1});

        // In between nums
        for (int i = 0; i < size - 1; ++i) {
            if (nums[i + 1] - nums[i] > 1) result.emplace_back(vector<int>{nums[i] + 1, nums[i+1] - 1});
        }

        // Between last num of nums and upper
        if (upper - nums.back() > 1) result.emplace_back(vector<int>{nums.back() + 1, upper});

        return result;
    }
};