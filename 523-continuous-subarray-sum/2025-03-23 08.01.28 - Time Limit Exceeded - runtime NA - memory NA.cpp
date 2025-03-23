class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      int size = nums.size();
      vector<int> prefixSum;
      prefixSum.emplace_back(0);

      for (const auto& num : nums) prefixSum.emplace_back(num + prefixSum.back());

      for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 2; j <=size; ++j) {
          if ((prefixSum[j] - prefixSum[i]) % k == 0) return true;
        }
      }
      return false;
    }
};