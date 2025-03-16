class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int size = nums.size();
      unordered_map<int, int> freqMap;

      int subarrays = 0;
      int sum = 0;
      freqMap.try_emplace(0, 1);

      for (int i = 0; i < size; ++i) {
        sum += nums[i];
        if (freqMap.contains(sum - k)) subarrays += freqMap[sum - k];
        ++freqMap[sum];
      }

      return subarrays;
    }
};