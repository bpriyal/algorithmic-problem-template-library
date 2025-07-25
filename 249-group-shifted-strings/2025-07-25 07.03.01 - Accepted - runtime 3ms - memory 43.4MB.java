class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        int n = strings.length;
        Map<List<Integer>, List<String>> patternToStr = new HashMap();
        for (String s : strings) {
            List<Integer> temp = new ArrayList();
            temp.add(0);
            for (int i = 1; i < s.length(); ++i) {
                int val = (s.charAt(i) - s.charAt(i - 1) + 26) % 26;
                temp.add(val);
            }
            patternToStr.computeIfAbsent(temp, x -> new ArrayList<String>()).add(s);
        }

        return new ArrayList(patternToStr.values());

    }
}