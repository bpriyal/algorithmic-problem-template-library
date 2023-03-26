class Solution {
    int minSplitsRequired(const vector<int>& nums, int low, int high, int maxAllowedSum, int k) {
        int splits = 0;
        int runSum = 0;
        int size = nums.size();

        for (int i = 0; i < size; ++i) {
            if (runSum + nums[i] >= maxAllowedSum) {
                ++splits;
                runSum = nums[i];
                continue;
            }
            runSum += nums[i];
        }

        return splits + 1;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int size = nums.size();
        int maxElement = 0;
        int sum = 0;

        for (auto num : nums) {
            sum += num;
            maxElement = max(num, maxElement);
        }

        int low = maxElement;
        int high = sum;
        int minMaxSubArraySum = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (minSplitsRequired(nums, low, high, mid, k) <= k) {
                minMaxSubArraySum = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return minMaxSubArraySum - 1;
    }
};