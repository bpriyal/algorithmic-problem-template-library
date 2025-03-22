class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
      int size = nums.size();
      unordered_map<int, int> numToFreqMap;
      int sum = 0;
      for (auto num : nums) {
        ++numToFreqMap[num];
        sum += num;
      }

      int outlier = INT_MIN;
      for (auto num : nums) {
        auto potentialOutlier = sum - 2 * num;
        if ((num == potentialOutlier && numToFreqMap[potentialOutlier] >= 2) ||
            (num != potentialOutlier && numToFreqMap[potentialOutlier]))
          outlier = max(outlier, potentialOutlier);
      }
      
      return outlier;
    }
};