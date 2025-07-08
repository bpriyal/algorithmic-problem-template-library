class Solution {
    public boolean closeStrings(String word1, String word2) {
        Map<Character, Integer> map1 = new HashMap();
        Map<Character, Integer> map2 = new HashMap();

        for (char c : word1.toCharArray()) {
            map1.put(c, map1.getOrDefault(c,0) + 1);
        }
        for (char c : word2.toCharArray()) {
            map2.put(c, map2.getOrDefault(c,0) + 1);
        }
        if (map1.equals(map2)) return true;
        List<Integer> list1 = new ArrayList<>(map1.values());
        List<Integer> list2 = new ArrayList<>(map2.values());

        Collections.sort(list1);
        Collections.sort(list2);

        // Set<Character> = new HashSet(map1.keySet());

        if (list1.equals(list2) && map1.keySet().equals(map2.keySet())) return true;

        return false;
    }
}