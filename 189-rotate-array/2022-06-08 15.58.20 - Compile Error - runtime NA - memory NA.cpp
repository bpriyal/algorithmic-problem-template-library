class Solution {
    void revers(vector<int> &nums, int l, int r) {
        for (int i = l;i < (l + r)/2;++i) {
            int temp = nums[i];
            nums[i] = nums[(r+l)-i-1];
            nums[(r+l)-i-1] = temp;
        }
    }
    
    void printvec(vector<int> &nums) {
        for(int i = 0;i < nums.size();++i) {
            cout<<nums[i]<<"\t";
        }
        cout<<"\n";
    }
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (k > size) return nums;
        revers(nums, 0, size);
        printvec(nums);
        revers(nums, 0, k);
        printvec(nums);
        revers(nums, k, size);
        printvec(nums);
    }
};