class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sumN = (size*(size+1))/2;
        int sum = 0;
        for(int num:nums) {
            sum += num;
        }
        return sumN-sum;
    }
};