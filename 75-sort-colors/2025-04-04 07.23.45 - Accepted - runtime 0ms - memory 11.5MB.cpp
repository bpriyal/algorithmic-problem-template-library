class Solution {
public:
    void sortColors(vector<int>& nums) {
      vector<int> cache(3, 0);
      for (int num : nums) ++cache[num];
      int k = 0;
      for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j < cache[i]; ++j) nums[k++] = i;
      }
    }
};