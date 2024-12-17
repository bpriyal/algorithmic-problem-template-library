class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < size - 2 && nums[i] <= 0; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int j = i + 1;
                int k = size - 1;
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        result.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                        ++j;
                        --k;
                    }
                    else if (sum < 0) ++j;
                    else if (sum > 0) --k;
                }
            }
        }
        return result;
    }
};