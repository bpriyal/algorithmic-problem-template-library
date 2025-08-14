class Solution {
    public int strStr(String haystack, String needle) {
        int hn = haystack.length();
        int nn = needle.length();
        int[] lborder = new int[hn + 1];
        int start = -1;
        for (int i = 1; i < hn + 1; ++i) {
            if (haystack.charAt(i - 1) != needle.charAt(lborder[i - 1])) {
                if (start != -1) {
                    if (hn - start < nn) return -1;
                    i = start;
                }
            }
            else if (haystack.charAt(i - 1) == needle.charAt(i - 1))
                lborder[i] = lborder[i - 1] + 1;
            if (lborder[i] > 0) start = i;
            if (lborder[i] == needle.length()) return i - needle.length();
        }
        return -1;
    }
}