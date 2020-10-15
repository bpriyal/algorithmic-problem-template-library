class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        /*vector<int> temp(nums);
        for(int i = 0;i < size;i++) {
            int pos = (i+k)%size;
            nums[pos] = temp[i];
        }
        return;*/
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};