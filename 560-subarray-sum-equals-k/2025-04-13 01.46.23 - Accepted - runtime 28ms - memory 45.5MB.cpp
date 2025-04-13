class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int size = nums.size();
      unordered_map<int, int> sumToFreqMap;
      sumToFreqMap.emplace(0, 1);
      int runningSum = 0;
      int subArrays = 0;

      for (int num : nums) {
        runningSum += num;
        auto it = sumToFreqMap.find(runningSum - k);
        if (it != sumToFreqMap.end()) subArrays += it->second;
        ++sumToFreqMap[runningSum];
      }

      return subArrays;
    }
};