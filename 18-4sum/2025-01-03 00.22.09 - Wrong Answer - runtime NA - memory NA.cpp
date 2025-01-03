class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        for (int i = 0; i < size - 3 && (target >= 0? (nums[i] <= target) : (nums[i] >= target)); ++i) {
            for (int j = i + 1; j < size - 2; ++j) {
                int x = j + 1;
                int y = size - 1;
                while (x < y) {
                    auto sum = nums[i] + nums[j] + nums[x] + nums[y];
                    if (sum == target) {
                        result.emplace(vector<int>{nums[i], nums[j], nums[x], nums[y]});
                        ++x;
                        --y;
                    }
                    else if (sum < target) ++x;
                    else if (sum > target) --y;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};