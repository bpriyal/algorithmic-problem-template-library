class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // [4,3,2,1] [7,6,5]
        
        int size = nums.size();
        
        if (size < 2) return;
        
        reverse(nums.begin(), nums.begin() + size - k%size);
        reverse(nums.end() - k%size, nums.end());
        
        reverse(nums.begin(), nums.end());
    }
};