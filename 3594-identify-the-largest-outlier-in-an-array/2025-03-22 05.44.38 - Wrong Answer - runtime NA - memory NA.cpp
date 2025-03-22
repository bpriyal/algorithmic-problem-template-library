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
        cout << num << endl;
        auto potentialOutlier = sum - 2 * num;
        auto it = numToFreqMap.find(potentialOutlier);
        if (it != numToFreqMap.end()) outlier = max(outlier, potentialOutlier);
      }
      
      return outlier;
    }
};