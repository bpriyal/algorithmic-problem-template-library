class Solution {
    int size;
    int util(const vector<int>& nums,int sum,int pos,bool adj) {
        if (pos == size) {
            return sum;
        }
        return max(adj? util(nums,sum+nums[pos],pos+1,false):-1,util(nums,sum,pos+1,true));
    } 
public:
    int rob(vector<int>& nums) {
        size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return nums[0];
        }
        //return util(nums,0,0,true);
        nums[1] = max(nums[0],nums[1]);
        for(int i = 2;i<size;++i) {
            nums[i] = max(nums[i]+nums[i-2],nums[i-1]);
        }
        return nums[size-1];
    }
};

