class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int ep = 0, np = 1;
        vector<int> result(nums.size(), 0);
        for (auto num : nums) {
            if (num > 0) {
                result[ep] = num;
                ep += 2;
            } else {
                result[np] = num;
                np += 2;
            }
        }
        return result;
    }
};