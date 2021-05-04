class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        bool flag = true;
        
        for(int i = 0;i < size - 1;++i) {
            if (nums[i] > nums[i+1]) {
                if (flag) {
                    flag = false;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};