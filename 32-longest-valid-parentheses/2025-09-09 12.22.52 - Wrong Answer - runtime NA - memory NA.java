class Solution {
    public int longestValidParentheses(String s) {
        int left = 0;
        int count = 0;
        int max = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                left++;
            } else {
                if (left == 0) {
                    max = Math.max(count, max);
                    count = 0;
                } else {
                    left--;
                    count++;
                }
            }
        }
        max = Math.max(count, max);
        return max*2;
    }
}