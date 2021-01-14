class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
    vector<int> sum(n);
    sum[0] = nums[n - 1];
    for (int i = n - 2, j = 1; i >= 0; i--, j++) {
      sum[j] = sum[j - 1] + nums[i];
    }
    for (int i = 1; i < n; i++) {
      nums[i] += nums[i - 1];
    }
    int res = INT_MAX;
    for (int i = 0; i < n && nums[i] < x; i++) {
      int c = lower_bound(sum.begin(), sum.begin() + n - 1 - i, x - nums[i]) -
              sum.begin();
      if (c == n - 1 - i || sum[c] != x - nums[i]) continue;
      res = min(res, i + 1 + c + 1);
    }
    int c = lower_bound(sum.begin(), sum.end(), x) - sum.begin();
    if (c < n && sum[c] == x) 
		res = min(res, c + 1);
    c = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
    if (c < n && nums[c] == x) 
		res = min(res, c + 1);
    if (res == INT_MAX) 
		res = -1;
    return res;
    }
};