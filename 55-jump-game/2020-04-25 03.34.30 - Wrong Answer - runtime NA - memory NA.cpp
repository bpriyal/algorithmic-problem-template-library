class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size =nums.size();
        if (size == 0) return false;
        if (size == 1) return true;
        int jump= 1;
        while (jump<size-1) {
            if (nums[jump] == 0) return false;
            jump = jump + nums[jump];
        }
        if (jump == size -1) return true;
        return false;
    }
};