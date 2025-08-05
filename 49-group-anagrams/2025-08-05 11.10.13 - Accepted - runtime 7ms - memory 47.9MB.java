class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n = strs.length;
        Map<String, List<String>> carrToList = new HashMap();
        for (int i = 0; i < n; ++i) {
            char[] carr = strs[i].toCharArray();
            Arrays.sort(carr);
            String tempKey = new String(carr);
            carrToList.computeIfAbsent(tempKey, x -> new ArrayList()).add(strs[i]);
        }
        // System.out.println(String.valueOf(sign[0]));
        return (new ArrayList(carrToList.values()));
    }
}