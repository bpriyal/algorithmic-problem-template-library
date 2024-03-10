class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int size = nums.size();
        int missingNumber = nums.front();
        int i = 0;
        for (int i = 0; i < size - 1; ++i) {
            int noOfMissing = nums[i + 1] - nums[i] - 1;
            if (noOfMissing >= k) return nums[i] + k;
            k -= noOfMissing;
        }
        return nums.back() + k;
    }
};