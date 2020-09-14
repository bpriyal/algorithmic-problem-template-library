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
        return util(nums,0,0,true);
    }
};