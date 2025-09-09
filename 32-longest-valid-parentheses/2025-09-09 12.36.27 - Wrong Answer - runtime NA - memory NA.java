class Solution {
    public int longestValidParentheses(String s) {
        int left = 0;
        int count = 0;
        int max = 0;
        int closeLast = s.lastIndexOf(')');
        int ind = 0;
        int right = 0;
        for (char c : s.toCharArray()) {
            if (ind > closeLast) break;
            if (ind == closeLast) {
                if (left > 1) {
                    count = 0;
                    for (int i = ind; i >= 0; --i) {
                        if (c == ')') {
                            right++;
                        } else {
                            if (right <= 0) {
                                max = Math.max(closeLast - i, max);
                            }
                        }
                    }
                }
            }
            if (c == '(') {
                left++;
            } else {
                if (left <= 0) {
                    max = Math.max(count, max);
                    count = 0;
                } else {
                    left--;
                    count++;
                }
            }
            ind++;
        }
        max = Math.max(count, max);
        return max*2;
    }
}

// ((())

// ()(()