class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int size = nums.size();
      vector<int> prefixSum(size + 1, 0);

      for (int i = 0; i < size; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
      }

      int subarrays = 0;
      for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size + 1; ++j) {
          if (prefixSum[j] - prefixSum[i] == k) ++subarrays;
        }
      }

      return subarrays;
    }
};