class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        boolean isT1Big = text1.length() > text2.length() ? true : false;
        String big = isT1Big ? text1 : text2;
        String small = isT1Big ? text2 : text1;
        int max = 0;

        int count = 0;
        for (int i = 0; i < small.length(); ++i) {
            char c = small.charAt(i);
            int ind = big.indexOf(c);
            if (ind != -1) {
                big = big.substring(big.indexOf(c) + 1);
                count++;
            }
        }
        return count;

    }

    class Node {
        public char c;
        List<Node> children;
    }
}