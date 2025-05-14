class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> freq = new HashMap<>();
        int ind = -1;
        for (int i = 0; i < nums.length; ++i) {
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
            if (freq.get(nums[i]) > nums.length/2) {
                ind = i;
                break;
            }
        }
        return nums[ind];
    }
}