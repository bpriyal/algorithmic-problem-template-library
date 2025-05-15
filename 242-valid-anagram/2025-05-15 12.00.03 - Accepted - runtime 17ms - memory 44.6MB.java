class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> anagramChars = new HashMap<>();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            anagramChars.put(c, anagramChars.getOrDefault(c, 0) + 1);
        }
        for (int i = 0; i < t.length(); ++i) {
            char c = t.charAt(i);
            // anagramChars.put(c, anagramChars.getOrDefault(c, 0) + 1);
            if (!anagramChars.containsKey(c)) {
                return false;
            } else {
                if (anagramChars.get(c) == 1) {
                    anagramChars.remove(c);
                } else {
                    anagramChars.replace(c,anagramChars.get(c) - 1);
                }
            }
        }
        return (anagramChars.size() == 0);
    }
}