class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool wiggle = false;
        sort(nums.begin(), nums.end());
        for (int i = 2; i < nums.size(); i += 2) {
            swap(nums[i - 1], nums[i]);
        }
    }
};

// 3 5 1 4 2 6

