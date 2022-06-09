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
        k = k % size;
        reverse(nums, 0, size);
        reverse(nums, 0, k);
        reverse(nums, k, size);
    }
};