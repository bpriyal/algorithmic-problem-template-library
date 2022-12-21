class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        set<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                int k = j + 1;
                int l = size - 1;
                while (k < l) {
                    long long tempSum = nums[i] + nums[j];
                    tempSum += nums[k];
                    tempSum += nums[l];
                    if (target == tempSum) result.emplace(vector<int>({nums[i], nums[j], nums[k++], nums[l--]}));
                    if (target < tempSum) --l;
                    else ++k;
                }
            }
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
};