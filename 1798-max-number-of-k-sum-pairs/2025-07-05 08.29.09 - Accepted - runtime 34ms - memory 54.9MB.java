class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> numsToFreq = new HashMap();
        int count = 0;
        for (int i : nums) {
            if (numsToFreq.containsKey(k - i)) {
                int freq = numsToFreq.get(k - i);
                if (freq > 1) numsToFreq.put(k - i, freq - 1);
                else numsToFreq.remove(k - i);
                count++;
            } else {
                numsToFreq.put(i, numsToFreq.getOrDefault(i,0) + 1);
            }
        }
        return count;
    }
}