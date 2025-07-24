import java.util.*;
import java.util.stream.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> numToFreq = new HashMap<>();
        for (int n : nums) {
            numToFreq.put(n, numToFreq.getOrDefault(n, 0) + 1);
        }

        // Sort the map entries by frequency in descending order, get keys
        List<Integer> keys = numToFreq.entrySet()
            .stream()
            .sorted(Map.Entry.<Integer, Integer>comparingByValue().reversed())
            .map(Map.Entry::getKey)
            .limit(k)
            .collect(Collectors.toList());

        return keys.stream().mapToInt(Integer::intValue).toArray();
    }
}
