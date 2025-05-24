class Solution {
    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        final int MOD = 1_000_000_007;
        long[] count = new long[26];

        for (char ch : s.toCharArray()) {
            count[ch - 'a']++;
        }

        for (int round = 0; round < t; ++round) {
            long[] newRound = new long[26];

            for (int i = 0; i < 26; ++i) {
                int n = nums.get(i);
                for (int cnt = 0; cnt < n; cnt++) {
                    int j = (i + 1 + cnt) % 26;
                    newRound[j] = (newRound[j] + count[i]) % MOD;
                }
            }
            count = newRound;
        }

        long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + count[i]) % MOD;
        }

        return (int) ans;
    }
}
