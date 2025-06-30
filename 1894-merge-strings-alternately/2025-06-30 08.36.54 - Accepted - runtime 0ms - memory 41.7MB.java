class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int n = Math.min(word1.length(), word2.length());
        int i;
        for (i = 0; i < n; ++i) {
            sb.append(word1.charAt(i));
            sb.append(word2.charAt(i));
        }
        if (word1.length() > n) {
            sb.append(word1.substring(i));
        } else {
            sb.append(word2.substring(i));
        }
        return sb.toString();
    }
}