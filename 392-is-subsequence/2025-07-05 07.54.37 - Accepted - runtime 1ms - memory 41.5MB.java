class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0;
        if (s == null || t == null) return false;
        if (s.length() == 0) return true;
        if (t.length() == 0) return false;
        for (char c : t.toCharArray()) {
            if (i < s.length() && s.charAt(i) == c) {
                i++;
            }
        }
        return (i == s.length());
    }
}