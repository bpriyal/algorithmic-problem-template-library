class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
        int majorityEle;
        for (int i = 0 ; i < size; ++i) {
            if (count == 0) {
                majorityEle = nums[i];
                ++count;
            } else if (nums[i] == majorityEle) ++count;
            else --count;
        }
        return majorityEle;
    }
};