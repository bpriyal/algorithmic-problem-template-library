class Solution {
    public int longestSubarray(int[] nums) {
        int sum = 0;
        int max = 0;
        int balance = 1;

        int start = 0;
        for(int i = start; i < nums.length; ++i){
            if(nums[i] == 1){
                sum++;
            }
            else if(balance > 0){      
                balance--;
                sum++;
            }
            else if(balance == 0){
                i = start++;
                balance = 1;
                sum = 0;
            }

            if(max < sum){
                max = sum;
            }
        }
        return max - 1;
    }
}