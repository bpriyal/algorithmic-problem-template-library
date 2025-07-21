class Solution {
    public boolean isPalindrome(String s) {
        char[] carr = s.toCharArray();
        int i = 0;
        int j = carr.length - 1;
        while (i <= j) {
            if(!Character.isLetterOrDigit(carr[i])) {i++; continue;}
            if(!Character.isLetterOrDigit(carr[j])) {j--; continue;}
            char c1 = carr[i];
            char c2 = carr[j];
            if (Character.toLowerCase(carr[i++]) != Character.toLowerCase(carr[j--])) return false;
        }
        return true;
    }
}