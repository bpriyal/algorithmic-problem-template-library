class Solution {
    public int longestOnes(int[] nums, int k) {
        int sum = 0;
        int max = 0;
        int balance = k;

        int start = 0;
        for(int i = start; i < nums.length; ++i){
            if(balance > 0){ 
                ++sum;
                if(nums[i] == 0){
                    --balance;
                }         
            }
            else{
                i = ++start;
                balance = k;
                sum = 0;
            }

            if(max < sum){
                max = sum;
            }
        }
        return max;
    }
}