class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0;
        if (s == null || t == null) {
            return false;
        }
        if (s.length() == 0 || t.length() == 0) {
            return true;
        }
        for (char c : t.toCharArray()) {
            if (s.charAt(i) == c) {
                i++;
            }
        }
        return (i == s.length());
    }
}