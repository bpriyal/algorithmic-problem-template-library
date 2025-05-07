class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> complementToIndex = new HashMap<>();
        int[] result = new int[2];
        for (int i = 0; i < nums.length; ++i) {
            if (complementToIndex.containsKey(nums[i])) {
                result[0] = complementToIndex.get(nums[i]);
                result[1] = i;
                break;
            }
            complementToIndex.put(target - nums[i], i);
        }
        return result;
    }
}