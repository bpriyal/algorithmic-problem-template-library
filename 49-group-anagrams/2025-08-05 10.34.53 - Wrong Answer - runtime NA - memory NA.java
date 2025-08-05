class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<Set<Character>, List<String>> setToList = new HashMap();
        for (String s : strs) {
            Set<Character> temp = new TreeSet();
            for (char c : s.toCharArray()) {
                temp.add(c);
            }
            setToList.computeIfAbsent(temp, x -> new ArrayList()).add(s);
        }
        List<List<String>> ret = new ArrayList(setToList.values());
        return ret;
    }
}