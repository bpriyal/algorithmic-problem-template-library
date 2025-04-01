class Solution {
    int numSize, queriesSize;
    bool isZero(const vector<int>& nums) {
      int sum = 0;
      for (const int& num : nums) sum += num;
      return sum == 0;
    }
    bool possible(vector<int> nums, const vector<vector<int>>& queries, int K) {
      for (int k = 0; k < K; ++k) {
        for (int i = queries[k][0]; i <= queries[k][1]; ++i) {
          nums[i] = max(0, nums[i] - queries[k][2]);
        }
        if (isZero(nums)) return true;
      }
      return false;
    }

    bool possibleFaster(const vector<int>& nums, const vector<vector<int>>& queries, int K) {
      vector<int> diffArray(numSize + 1, 0);
      for (int k = 0; k < K; ++k) {
        diffArray[queries[k][0]] += queries[k][2];
        diffArray[queries[k][1] + 1] -= queries[k][2];
      }

      int sum = 0;
      for (int i = 0; i < numSize; ++i) {
        sum += diffArray[i];
        if (sum < nums[i]) return false;
      }

      return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
      numSize = nums.size();
      queriesSize = queries.size();

      if (!possibleFaster(nums, queries, queriesSize)) return -1;
      int left = 0, right = queriesSize;

      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (possibleFaster(nums, queries, mid)) {
          right = mid - 1;
        }
        else left = mid + 1;
      }
      return left;
    }
};