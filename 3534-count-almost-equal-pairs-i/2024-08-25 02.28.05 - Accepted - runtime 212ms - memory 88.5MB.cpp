class Solution {
    bool almostEqual(int n1, int n2) {
      auto str1 = std::to_string(n1);
      auto str2 = std::to_string(n2);
      int size1 = str1.size();
      int size2 = str2.size();
      int maxSize = max(size1, size2);
      while (size1 != maxSize) {
        str1 = "0" + str1;
        ++size1;
      }
      while (size2 != maxSize) {
        str2 = "0" + str2;
        ++size2;
      }
      vector<int> freq1(10), freq2(10);
      int diffs = 0;
      for (int i = 0; i < maxSize; ++i) {
        if (str1[i] != str2[i]) ++diffs;
        if (diffs > 2) return false;
        ++freq1[str1[i] - '0'];
        ++freq2[str2[i] - '0'];
      }
      return freq1 == freq2;
    }
public:
    int countPairs(vector<int>& nums) {
      int size = nums.size();
      int count = 0;

      for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
          count += almostEqual(nums[i], nums[j]);
        }
      }
      return count;
    }
};