class Solution {
    static constexpr long mod = 1000000007;
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int size = nums.size();
        for (int op = 0; op < k; ++op) {
          auto it = min_element(nums.begin(), nums.end());
          *it = (((*it) % mod) * multiplier) % mod;
        }
        for (auto& num : nums) num = num % mod;
        return nums;
    }
};