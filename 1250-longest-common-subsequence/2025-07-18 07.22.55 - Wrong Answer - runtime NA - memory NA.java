class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        boolean isT1Big = text1.length() > text2.length() ? true : false;
        String big = isT1Big ? text1 : text2;
        String small = isT1Big ? text2 : text1;
        Stack<Integer> inds = new Stack();
        int max = 0;
        int count = 0;
        int ind = 0;
        int lastInd = 0;
        for (int i = 0; i < small.length(); ++i) {
            char c = small.charAt(i);
            // String subs = big.substring(lastInd);
            ind = big.indexOf(c);
            if (ind != -1) {          
                while(!inds.isEmpty() && ind <= inds.peek()) {         
                    inds.pop();
                }
                lastInd = ind;
                inds.push(ind);
                count = inds.size();
                max = Math.max(count, max);
                // big = big.substring(ind + 1);                   
            }
        }
        return max;
    }
}