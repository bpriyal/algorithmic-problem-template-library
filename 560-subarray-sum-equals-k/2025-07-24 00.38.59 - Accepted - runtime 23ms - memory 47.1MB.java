class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> runToFreq = new HashMap();
        runToFreq.put(0, 1);
        int total = 0;
        int count = 0;
        for (int i = 0; i < nums.length; ++i) {
            total += nums[i];
            if (runToFreq.containsKey(total - k)) count += runToFreq.get(total - k);
            runToFreq.put(total, runToFreq.getOrDefault(total, 0) + 1);
        }
        return count;
    }
}

// 1 2 3 -4 5 -6 7 8 -9 10 11

// 0 1 3 6  2  7 1 8 16 7 17 28



// k = 

// 1-5
// 1- -9
// 2-7


// 28 27 25 22 26 21 27 20 12 21 11



// 0 3
