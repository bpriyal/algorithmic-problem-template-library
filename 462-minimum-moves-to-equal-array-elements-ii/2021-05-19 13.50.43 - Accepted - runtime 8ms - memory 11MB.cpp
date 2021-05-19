class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int result = 0;
        sort(nums.begin(),nums.end());
        
        int mid = nums.size()/2;
        
        for(int i = 0;i < nums.size();++i) {
            if (i != mid) {
                result += abs(nums[i]-nums[mid]);
            }
        }
        
        return result;
    }
};