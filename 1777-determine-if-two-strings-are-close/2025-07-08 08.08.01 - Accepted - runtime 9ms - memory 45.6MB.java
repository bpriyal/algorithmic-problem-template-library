class Solution {
    public boolean closeStrings(String word1, String word2) {
        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        for (char c : word1.toCharArray()) {
            freq1[c - 'a']++;
        }
        for (char c : word2.toCharArray()) {
            freq2[c - 'a']++;
        }

        int i;
        for (i = 0; i < 26; ++i) {
            if(freq1[i] != freq2[i]) break;
        }
        if (i == 26) return true;

        for (i = 0; i < 26; ++i) {
            if (!(freq1[i] == 0 && freq2[i] == 0)) {
                if (!(freq1[i] > 0 && freq2[i] > 0))
                    break;
            }
        }
        Arrays.sort(freq1);
        Arrays.sort(freq2);
 
        return ((i == 26) && (Arrays.equals(freq1,freq2)));
    }
}