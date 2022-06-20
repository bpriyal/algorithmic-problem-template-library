class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        
        int l = 0;
        int r = size - 1;
        
        vector<int> result(size);
        
        while (l <= r) {
            int sq1 = nums[l]*nums[l];
            int sq2 = nums[r]*nums[r];
            
            if (sq1 > sq2) {
                result[size - 1] = sq1;
                --size;
                ++l;
            } else {
                result[size - 1] = sq2;
                --size;
                --r;
            } 
        }
        
        return result;
    }
};