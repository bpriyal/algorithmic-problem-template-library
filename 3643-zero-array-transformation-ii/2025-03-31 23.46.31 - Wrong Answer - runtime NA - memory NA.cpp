class Solution {
    int numSize, queriesSize;
    bool isZero(const vector<int>& nums) {
      int sum = 0;
      for (const int& num : nums) {
        // cout << num << ",";
        sum += num;
      }
      cout << endl;
      return sum == 0;
    }
    bool possible(vector<int>& nums, const vector<vector<int>>& queries, int K) {
      for (int k = 0; k < K; ++k) {
        for (int i = queries[k][0]; i <= queries[k][1]; ++i) {
          nums[i] = max(0, nums[i] - queries[k][2]);
        }
        if (isZero(nums)) return true;
      }
      return false;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
      if (isZero(nums)) return 0;
      numSize = nums.size();
      queriesSize = queries.size();

      int left = 0, right = queriesSize;

      while (left <= right) {
        // cout<<left<<","<<right<<endl;
        int mid = left + (right - left) / 2;
        if (possible(nums, queries, mid)) right = mid - 1;
        else left = mid + 1;
      }
      return isZero(nums) ? left : -1;
    }
};