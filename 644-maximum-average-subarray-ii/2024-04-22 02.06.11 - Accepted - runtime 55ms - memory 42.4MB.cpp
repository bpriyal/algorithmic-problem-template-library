class Solution {
    bool check(const vector<int>& nums, int k, double mid) {
        double minSum = 0.0, runningSum = 0.0, prevSum = 0.0;
        for (int i = 0; i < k; ++i) {
            runningSum += nums[i] - mid;
        }
        if (runningSum >= 0) return true;

        for (int i = k; i < nums.size(); ++i) {
            runningSum += nums[i] - mid;
            prevSum += nums[i - k] - mid;
            minSum = min(minSum, prevSum);
            if (runningSum - minSum >= 0) return true;
        }
        return false;
    }
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size();
        double minElement = *std::min_element(nums.begin(), nums.end());
        double maxElement = *std::max_element(nums.begin(), nums.end());
        double prevMid = maxElement;
        double error = INT_MAX;
        while (error > 0.00001) {
            double mid = minElement + (maxElement - minElement) / 2;
            cout<<mid<<endl;
            if (check(nums, k, mid)) minElement = mid + 1;
            else maxElement = mid - 1;
            error = abs(mid - prevMid);
            prevMid = mid;
        }
        return prevMid;
    }
};