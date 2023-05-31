class Solution {
    public void moveZeroes(int[] nums) {

        int lastPos = 0;

        for(int i = 0; i < nums.length; ++i){
            if(nums[i] == 0){
                if(i > 0 && nums[i-1] != 0){
                    lastPos = i;
                }
            }
            else{
                nums[lastPos] = nums[i];
                if(lastPos != i){
                    nums[i] = 0;
                } 
                lastPos++;
            }
        }
        for(int i = lastPos; i < nums.length; ++i){
            nums[i] = 0;
        }
    }
}