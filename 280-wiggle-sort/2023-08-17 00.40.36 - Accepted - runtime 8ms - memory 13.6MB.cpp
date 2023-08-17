class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // bool wiggle = false;
        // sort(nums.begin(), nums.end());
        // for (int i = 2; i < nums.size(); i += 2) {
        //     swap(nums[i - 1], nums[i]);
        // }

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i % 2) {
                if (nums[i] < nums[i + 1]) swap(nums[i], nums[i+1]);
            } else {
                if (nums[i] > nums[i + 1]) swap(nums[i], nums[i+1]);
            }
        }
    }
};

