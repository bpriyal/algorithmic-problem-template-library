class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<Set<List<Integer>>, List<String>> setToList = new HashMap();
        for (String s : strs) {
            Set<List<Integer>> keys = new HashSet();
            List<Integer> temp = new ArrayList();
            for (int i = 0; i < 26; ++i) temp.add(0);
            for (char c : s.toCharArray()) {               
                temp.set(c - 'a', temp.get(c - 'a') + 1);
            }
            keys.add(temp);
            setToList.computeIfAbsent(keys, x -> new ArrayList()).add(s);
        }
        List<List<String>> ret = new ArrayList(setToList.values());
        return ret;
    }
}