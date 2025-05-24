class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        if (envelopes == null || envelopes.length == 0) return 0;
        Arrays.sort(envelopes, new Comparator<int[]>() {
            public int compare (int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });
        int dp[] = new int[envelopes.length];
        dp[0] = 1;
        int MAX = 1;
        for (int n = 1; n < envelopes.length; ++n) { //check for nth envelope
            dp[n] = 1;
            for (int i = 0; i < n; ++i) {
                if (envelopes[n][0] > envelopes[i][0] && envelopes[n][1] > envelopes[i][1]) {
                    dp[n] = Math.max (dp[n], dp[i] + 1);
                }
            }
            MAX = Math.max (MAX, dp[n]);
        }
        return MAX;
    }

}