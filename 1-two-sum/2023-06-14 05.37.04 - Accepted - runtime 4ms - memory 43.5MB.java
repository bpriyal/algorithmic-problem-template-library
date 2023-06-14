class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> numsToFreq = new HashMap<>();
        for(int i = 0; i < nums.length; ++i){
            numsToFreq.put(nums[i],i);
        }
        for(int i = 0; i < nums.length; ++i){
            int complement = target - nums[i];
            if(numsToFreq.containsKey(complement) && numsToFreq.get(complement) != i) { 
                return new int [] { i, numsToFreq.get(complement)};
            }
                    
        }
        return null;
    }
}