class Solution {
    public boolean isValidPalindrome(String s, int k) {
        return checkPalindrome (new StringBuilder(s), k, 0);
    }

     boolean checkPalindrome (StringBuilder sb, int k, int ind) {
        if (k == 0) return false;
        int n = sb.length();
        for (int i = ind; i < n / 2; ++i) {
            if (sb.charAt(i) == sb.charAt(n - i - 1)) continue;
            else {
                StringBuilder temp = new StringBuilder(sb);
                temp.deleteCharAt(i);
                if (checkPalindrome (temp, k - 1, i)) return true;
                temp.setCharAt(i, sb.charAt(i));
                temp.deleteCharAt(n - 1 - i);
                if (checkPalindrome (temp, k - 1, i)) return true;
            }
        }
        return true;
     }
}