class Solution {
    int MAX = 0;
    public int lengthOfLongestSubstring(String s) {
        char[] carr = s.toCharArray();
        Map<Character, List<Integer>> charToInds = new HashMap();
        int i = 0;
        int win = 0;
        for (char c : s.toCharArray()) {
            if (!charToInds.containsKey(c)) {
                win++;
                charToInds.put(c, new ArrayList<Integer>(Arrays.asList(i)));
                MAX = Math.max(win,MAX);
            } else {
                int lastInd = charToInds.get(c).getLast();
                int checkWin = i - lastInd;
                if (checkWin <= win) win = checkWin;
                charToInds.get(c).add(i);
            }
            i++;
            // charToInds.computeIfAbsent(c, x -> new ArrayList()).add(i);     
        }
        return MAX;
    }
    
}