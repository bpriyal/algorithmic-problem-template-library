class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        int i = s.length() - 1;
        int len = 0;
        // for (int i = s.length() - 1; i >= 0; i--) {
            while (i >= 0 && s.charAt(i) != ' ') {
                len++; i--;
            }
        return len;
    }
}