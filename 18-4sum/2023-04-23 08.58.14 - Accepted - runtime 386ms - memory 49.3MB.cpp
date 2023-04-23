class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        set<vector<int>> quadruplets;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 3; ++i) {
            for (int j = i + 1; j < size - 2; ++j) {
                int k = j + 1;
                int l = size - 1;

                while (k < l) {
                    long quadSum = nums[i];
                    quadSum += nums[j];
                    quadSum += nums[k];
                    quadSum += nums[l];
                    if (quadSum == target) {
                        quadruplets.insert({nums[i], nums[j], nums[k], nums[l]});
                        ++k;
                        --l;
                    }
                    else if (quadSum < target) ++k;
                    else --l;
                }
            }
        }
        return vector<vector<int>>(quadruplets.begin(), quadruplets.end());
    }
};