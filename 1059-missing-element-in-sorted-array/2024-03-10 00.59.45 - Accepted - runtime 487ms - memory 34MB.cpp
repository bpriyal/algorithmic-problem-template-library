class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int size = nums.size();
        int missingNumber = nums.front();
        int i = 0;
        while (k) {
            if (i < size) {
                if (nums[i] == missingNumber) {
                    ++missingNumber;
                    ++i;
                    continue;
                }
            }
            --k;
            if (k == 0) return missingNumber;
            ++missingNumber;
        }
        return -1;
    }
};