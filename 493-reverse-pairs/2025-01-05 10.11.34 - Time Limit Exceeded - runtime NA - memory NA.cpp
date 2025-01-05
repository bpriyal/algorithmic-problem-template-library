class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int size = nums.size();
        int reversePairsCnt = 0;
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if ((nums[i] / 2.0) > static_cast<double>(nums[j])) ++reversePairsCnt;
            }
        }
        return reversePairsCnt;
    }
};