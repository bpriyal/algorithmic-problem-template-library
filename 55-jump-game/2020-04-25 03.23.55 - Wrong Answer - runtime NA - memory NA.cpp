class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size =nums.size();
        if (size == 0) return false;
        int jump= 0;
        while (jump<size-1) {
            if (nums[jump] == 0) return false;
            jump = jump + nums[jump];
        }
        if (jump == size -1) return true;
        return false;
    }
};