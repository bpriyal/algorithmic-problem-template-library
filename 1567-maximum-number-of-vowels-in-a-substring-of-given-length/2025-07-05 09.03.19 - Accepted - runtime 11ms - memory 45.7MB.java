class Solution {
    public int maxVowels(String s, int k) {
        int count = 0;
        int max = 0;
        int n = s.length();
        int[] isVowel = new int[n];

        for (int i = 0; i < n; ++i) if ((s.charAt(i) == 'a') || (s.charAt(i) == 'e') || (s.charAt(i) == 'i') || (s.charAt(i) == 'o') || (s.charAt(i) == 'u')) isVowel[i] = 1;
        for (int i = 0; i < k; ++i) count += isVowel[i];
        if (k == n) return count;
        max = count;
        for (int i = k; i < n; ++i) {
            count += isVowel[i] - isVowel[i - k];
            max = Math.max(count, max);
        }
        return max;
    }
}