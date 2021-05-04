class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        bool flag = true;
        int base;
        
        for(int i = 0;i < size - 1;++i) {
            if (nums[i] > nums[i+1]) {
                if (flag) {
                    flag = false;
                    base = nums[i];
                } else {
                    return false;
                }
            } else {
                if (!flag) {
                    if (nums[i+1] < base) {
                        return false;
                    } 
                }
            }
        }
        
        return true;
    }
};