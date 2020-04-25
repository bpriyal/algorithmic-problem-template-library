class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size =nums.size();
        if (size == 0) return false;
        if (size == 1) return true;
        if (nums[0] == 0) return false;
        int maxjump=0;
        for (int i=0;i<size;++i) {
            if (i > maxjump) {
                return false;
            }
            maxjump = ((i+nums[i]) > maxjump) ? (i+nums[i]) : maxjump;
        }
        return true;    
    }
}; 