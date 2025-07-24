class Solution {
    public String customSortString(String order, String s) {
        Map<Character, Integer> charToFreq = new HashMap();

        for (char c : s.toCharArray()) {
            charToFreq.put(c, charToFreq.getOrDefault(c, 0) + 1);
        }
        StringBuilder sb = new StringBuilder();
        for (char c : order.toCharArray()) {
            if (charToFreq.containsKey(c)) {
                int f = charToFreq.get(c);
                while(f-- > 0) sb.append(c);
                charToFreq.remove(c);
            }
        }
        for(char c : charToFreq.keySet()) {
                int f = charToFreq.get(c);
                while(f-- > 0) sb.append(c);
                // charToFreq.remove(c);
        }
        return sb.toString();
    }
}