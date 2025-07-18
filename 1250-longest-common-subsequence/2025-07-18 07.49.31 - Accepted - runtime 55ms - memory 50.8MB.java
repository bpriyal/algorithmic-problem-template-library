class Solution {
    int[][] memo;
    String text1;
    String text2;
    public int longestCommonSubsequence(String text1, String text2) {
       this.memo = new int[text1.length() + 1][text2.length() + 1];
       for (int i = 0; i < text1.length(); ++i) for (int j = 0; j < text2.length(); ++j) this.memo[i][j] = -1;
       this.text1 = text1;
       this.text2 = text2;
       return memoSolve(0,0);
    }

    int memoSolve(int p1, int p2) {
        if (memo[p1][p2] != -1) return memo[p1][p2];

        int option1 = memoSolve(p1 + 1, p2);
        int firstOccurrence = text2.indexOf(text1.charAt(p1), p2);
        int option2 = 0;
        if (firstOccurrence != -1) {
            option2 = 1 + memoSolve(p1 + 1, firstOccurrence + 1);
        }

        memo[p1][p2] = Math.max(option1, option2);
        return memo[p1][p2];
    }

}