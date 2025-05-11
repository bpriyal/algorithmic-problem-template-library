class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> charToLastInd = new HashMap<>();
        // s = s.trim();
        if (s == null || s.length() == 0) {
            return 0;
        }
        int max = 1;
        int start = 0;
        // int end = -1;
        int i = 0;
        for (; i < s.length(); ++i) {
             char c = s.charAt(i);
             if(!charToLastInd.containsKey(c)) {
                charToLastInd.put(c,i);
             } else {
                int window = i - start;
                if (max < window) {
                    max = window;
                }
                start = charToLastInd.get(c) + 1;
                charToLastInd.replace(c,i);
                // charToLastInd.remove(c);
             }
        }
        return Math.max(max, i - start);
    }
}