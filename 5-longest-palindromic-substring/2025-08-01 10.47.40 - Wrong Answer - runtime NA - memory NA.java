class Solution {
    public String longestPalindrome(String s) {
        if (s == null) return "";
        int n = s.length();
        if (n == 0 || n == 1) return s;
        if (n == 2)
            if (s.charAt(0) != s.charAt(1)) return String.valueOf(s.charAt(0));
            else return s;
        // int rad[] = new int[n];

        int max = 0;
        int left = 0;
        int right = 2;
        int center = n/2;
        boolean isEven = false;

        for (int i = 1; i < n; ++i) {
            right = i;
            left = i - 1;
            int rad = 0;

            while (((max == 1 && i - left == 1) || right < n) && left >= 0 && i <= right) {
                if (s.charAt(left) == s.charAt(right)) { //even length palindrome
                    rad++;
                    if (rad >= max) {
                        max = rad;
                        center = i;
                        isEven = true;
                    }
                    right++;
                    left--;
                } else break;
            }
        }

        left = 0;
        right = 2;
        int max2 = 0;

        for (int i = 1; i < n; ++i) {
            right = i + 1;
            left = 2*i - right;
            int rad = 0;

            while (left >= 0 && right < n && i < right) {
                if (s.charAt(left) == s.charAt(right)) {
                    rad++;
                    if (rad >= max2) {
                        max2 = rad;
                        center = i;
                        isEven = false;
                    }
                    right++;
                    left = 2*i - right;
                } else break;
            }
        }

        // if (max == 2) 

        if (2*max > (2*max2 + 1)) isEven = true;
        else isEven = false;

        if (isEven) {
            if (max == 1) return s.substring(center - 1, center + 1);
            else return s.substring(center - max + 1, center + max);
        }
        return s.substring(center - max2, center + max2 + 1);
    }
}