class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int i = 0, j = 0;
        if (word1 == null) return word2;
        if (word2 == null) return word1;
        for (;i < word1.length() && j < word2.length(); ++i, ++j) {
            sb.append(word1.charAt(i));
            sb.append(word2.charAt(j));
        }

        if (i < word1.length()) {
            //append remaining word 1 chars
            sb.append(word1.substring(i));
        } else if (j < word2.length()) {
            //append remaining word 2 chars
            sb.append(word2.substring(j));
        }

        return sb.toString();
    }
}