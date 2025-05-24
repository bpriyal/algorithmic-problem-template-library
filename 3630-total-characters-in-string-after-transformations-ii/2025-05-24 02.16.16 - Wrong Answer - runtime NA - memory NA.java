class Solution {
    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        int MOD = 1000000007;
        int count[] = new int[26];
        for (char ch : s.toCharArray()) {
            count[ch-'a']++;
        }

        for (int round = 0; round < t; ++round) {
            int newRound[] = new int[26];
        
            for (int i = 0; i < 26; ++i) {
                int n = nums.get(i);
                for (int cnt = 0; cnt < n; cnt++) {
                    int j = (i + 1 + cnt) % 26;
                    newRound[j] = (newRound[j] + count[i]) % MOD;
                }
            }
            count = newRound;
            // System.out.println();
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += count[i];
        }
        return ans % MOD;
    }
}