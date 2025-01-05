class Solution {
    vector<vector<int>> twoSum(const vector<int>& nums, long long target, int start) {
        int i = start;
        int j = nums.size() - 1;
        vector<vector<int>> result;
        while (i < j) {
            long long sum = nums[i] + nums[j];
            if (sum < target || (i > start && nums[i] == nums[i - 1])) ++i;
            else if (sum > target || (j < nums.size() - 1 && nums[j] == nums[j + 1])) --j;
            else result.emplace_back(vector<int>{nums[i++], nums[j--]});
        }
        return result;
    }
    vector<vector<int>> kSum(const vector<int>& nums, long long target, int start, int k) {
        vector<vector<int>> result;
        if (start == nums.size()) return result;
        long long average = target / k;
        if (nums[start] > average || nums.back() < average) return result;

        if (k == 2) return twoSum(nums, target, start);

        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                auto res = kSum(nums, target - nums[i], i + 1, k - 1);
                for (const auto& r : res) {
                    vector<int> temp;
                    temp.emplace_back(nums[i]);
                    temp.insert(temp.begin() + 1, r.begin(), r.end());
                    result.emplace_back(temp);
                }
            }
        }
        return result;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
};