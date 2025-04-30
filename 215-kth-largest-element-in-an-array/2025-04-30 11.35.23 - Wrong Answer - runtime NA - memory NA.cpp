class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      // priority_queue<int, vector<int>, greater<int>> pq;
      // for (int num : nums) {
      //   if (pq.size() < k) pq.emplace(num);
      //   else {
      //     if (pq.top() < num) {
      //       pq.pop();
      //       pq.emplace(num);
      //     }
      //   }
      // }
      // return pq.top();

      int left = 0, right = nums.size() - 1;
      while (left <= right) {
        int pivotIdx = left + (rand() % (right - left + 1));
        swap(nums[pivotIdx], nums[right]);
        int inflectionIdx = left;
        for (int i = left; i <= right; ++i) {
          if (nums[i] <= nums[right]) {
            swap(nums[inflectionIdx], nums[i]);
            ++inflectionIdx;
          }
        }
        swap(nums[inflectionIdx], nums[right]);
        if (inflectionIdx == k - 1) return nums[inflectionIdx];
        else if (inflectionIdx < k) left = inflectionIdx + 1;
        else right = inflectionIdx - 1;
      }
      return -1;
    }
};

// [3,2,1,5,6,4]