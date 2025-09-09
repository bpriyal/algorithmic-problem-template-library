class Solution {
    int MIN_ANS = Integer.MAX_VALUE;
    String Ans = new String();
    Map<Character, Integer> charToFreq = new HashMap();

    public String minWindow(String s, String t) {
        Map<Character, Integer> copyMap = new HashMap(charToFreq);
        int MIN = MIN_ANS;
        String Anscopy = Ans;
        for (char c : t.toCharArray()) {
            charToFreq.put(c, charToFreq.getOrDefault(c, 0) + 1);
        }
        backTrack(s, 0, charToFreq);
        return Ans;
    }
    void backTrack(String s, int startI, Map<Character, Integer> charToFreq) {
        Map<Character, Integer> copyMap = new HashMap(charToFreq);
        for (int i = startI; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (copyMap.containsKey(c))
                if (!copyMap.remove(c, 1)) copyMap.put(c, copyMap.get(c) - 1);
            if (copyMap.size() == 0) {
                if (MIN_ANS > i - startI + 1) {
                    Ans = s.substring(startI, i + 1);
                    MIN_ANS = i - startI + 1;
                }
                break;
            }
        }
        if (copyMap.size() > 0) return;
        else {
            backTrack(s, startI + 1, charToFreq);
        }
        return;
    }
}