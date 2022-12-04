class Solution {
    int size;
    
    int util(const vector<int>& nums, int k, int maxVal) {
        int runningSum = 0;
        int splits = 0;
        int i;

        for (i = 0; i < size && k; ++i) {
            if (runningSum + nums[i] > maxVal) {
                ++splits;
                runningSum = nums[i];
                continue;
            }
            runningSum += nums[i];
        }

        return splits + 1;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        size = nums.size();
        int maxElement = INT_MIN;
        int sum = 0;

        for (int num : nums) {
            sum += num;
            maxElement = max(maxElement, num);
        }

        int left = maxElement;
        int right = sum;
        int minLargestSum = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            cout<<mid<<endl;
            if (util(nums, k, mid) <= k) {
                minLargestSum = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return minLargestSum;
    }
};