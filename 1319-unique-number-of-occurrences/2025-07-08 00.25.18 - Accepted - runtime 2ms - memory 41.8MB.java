class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> unique = new HashMap();
        for (int i : arr) {
            unique.put(i,unique.getOrDefault(i, 0) + 1);
        }
        Set<Integer> occur = new HashSet();
        for (int i : unique.values()) {
            if (occur.contains(i)) return false;
            occur.add(i);
        }
        return true;
    }
}