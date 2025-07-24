class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> numToFreq = new TreeMap();
        for (int n : nums) {
            numToFreq.put(n, numToFreq.getOrDefault(n, 0) + 1);
        }
        Set<Integer> keys = new HashSet(numToFreq.keySet());
        if (k == numToFreq.size()) return keys.stream().mapToInt(Integer::intValue).toArray();
        for (int key : numToFreq.keySet()) {
            if (k <= 0) keys.remove(key);
            k--;
        }
        return keys.stream().mapToInt(Integer::intValue).toArray();
    }
}