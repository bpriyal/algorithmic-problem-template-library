class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int size = nums.size();
        for (int op = 0; op < k; ++op) {
          auto it = min_element(nums.begin(), nums.end());
          *it = *it * multiplier;
        }
        return nums;
    }
};