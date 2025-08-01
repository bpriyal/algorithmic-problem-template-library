class Solution {
    public String longestPalindrome(String s) {
        if (s == null) return "";
        int n = s.length();
        if (n == 0) return "";
        // int rad[] = new int[n];

        int max = 1;
        int left = 0;
        int right = 2;
        int center = n/2;
        boolean isEven = true;

        for (int i = 1; i < n - 1; ++i) {
            right = i + max;
            left = 2*i - right;
            int rad = 0;

            while (left >= 0 && right < n && i < right) {
                if (s.charAt(left) == s.charAt(i)) { //even length palindrome
                    rad++;
                    if (rad >= max) {
                        max = rad;
                        center = i;
                    }
                    right++;
                    left--;
                } else break;
            }
        }

        left = 0;
        right = 2;
        center = n/2;

        for (int i = 1; i < n - 1; ++i) {
            right = i + max;
            left = 2*i - right;
            int rad = 0;

            while (left >= 0 && right < n && i < right) {
                if (s.charAt(left) == s.charAt(right)) {
                    rad++;
                    if (rad >= max) {
                        max = rad;
                        center = i;
                        isEven = false;
                    }
                    right++;
                    left = 2*i - right;
                } else break;
            }
        }
        if (isEven) return s.substring(center - max, center + max);
        return s.substring(center - max, center + max + 1);
    }
}