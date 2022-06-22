class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        
        if (size < 2) {
            return;
        }
        
        int p1 = 0;
        int p2 = 1;
        
        while(p2 < size) {
            // cout<<nums[p1]<<"\t"<<nums[p2]<<"\n";
            if (nums[p1] == 0) {
                if (nums[p2] == 0) {
                    ++p2;
                } else {
                    int temp = nums[p1];
                    nums[p1] = nums[p2];
                    nums[p2] = temp;

                    ++p1;
                    ++p2;
                }
            } else {
                ++p1;
                ++p2;
            } 
        }
    }
};