class Solution {
    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        int count[] = new int[26];
        for (char ch : s.toCharArray()) {
            count[ch-'a']++;
            System.out.println(Integer.valueOf((ch-'a')).toString() + " " + count[ch-'a']);
        }

        for (int round = 0; round < t; ++round) {
            int newRound[] = new int[26];
            System.out.println("Round " + round+1);

            for (int i = 0; i < 26; ++i) { //count loop count[i] -> a freq
                System.out.println("a + " + i);

                int n = nums.get(i);
                System.out.println("how many chars next to replace? " + n);
                int cnt = 0;
                System.out.println(" ");
                System.out.println((i + 1) % 26);
                for (int j = (i + 1) % 26; cnt < n ; cnt++ ) { //wrap it around --> ?? 
                    newRound[j] += count[i];
                    System.out.println(j + " " + newRound[j]);
                    j = (j+1)%26;
                }
            }
            count = newRound;
            System.out.println();
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += count[i];
        }
        return ans%1000000007;
    }
}