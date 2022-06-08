class Solution {
    void reverse(vector<int> &nums, int l, int r) {
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
        if (k > size) {
            if (k%2 != 0) reverse(nums, 0, size);
            return;
        }
        reverse(nums, 0, size);
        printvec(nums);
        reverse(nums, 0, k);
        printvec(nums);
        reverse(nums, k, size);
        printvec(nums);
    }
};