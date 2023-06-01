class Solution {
    public int maxOperations(int[] nums, int k) {
        Arrays.sort(nums);
        int i = 0;
        int j = nums.length - 1;
        // int sum = INTEGER.MIN_VALUE;
        int noOfOps = 0;

        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == k){
                noOfOps++;
                i++;
                j--;
            } else if(sum < k){
                i++;
            } else if(sum > k){
                j--;
            }
        }

        return noOfOps;
    }
}