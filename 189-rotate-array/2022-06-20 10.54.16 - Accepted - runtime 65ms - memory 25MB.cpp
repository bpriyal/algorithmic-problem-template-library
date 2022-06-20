class Solution {
    void reverse(vector<int> &nums, int l, int r) {
        for (int i = l;i < (l + r)/2;++i) {
            int temp = nums[i];
            nums[i] = nums[(l+r) - i - 1];
            nums[(l + r) - i -1 ] = temp;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        reverse(nums, 0, size);
        reverse(nums, 0, k);
        reverse(nums, k, size);
    }
};