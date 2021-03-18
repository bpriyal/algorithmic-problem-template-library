class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int prev_diff=0;
        int len=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<0 && prev_diff>=0){
                prev_diff=-1;
                ++len;
            }
            else if(nums[i]-nums[i-1]>0 && prev_diff<=0){
                prev_diff=1;
                ++len;
            }
        }
        return len;
    }
};