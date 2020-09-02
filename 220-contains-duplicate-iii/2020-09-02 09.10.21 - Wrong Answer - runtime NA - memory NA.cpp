class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        int i = 0;
        while(i+k < size) {
            if (abs(nums[i]-nums[i+k]) <= t) {
                return true;
            }
            ++i;
        }
        return false;
    }
};