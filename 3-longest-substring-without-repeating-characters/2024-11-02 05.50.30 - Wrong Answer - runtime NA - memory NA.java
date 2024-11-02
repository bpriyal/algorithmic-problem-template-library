class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set currentSub = new HashSet<>();
        int longestSubL = -1;
        int longestSubR = -2;
        int l = 0;
        
        for ( int i = 0 ; i < s.length(); ++i ) {
            char c = s.charAt(i);
            if ( currentSub.contains(c) ) {
            // close old window
                if ( (i - l) > (longestSubR - longestSubL + 1) ) { 
                    // new longest sub
                    longestSubR = i - 1;
                    longestSubL = l;
                }
                
            // start new window
                l = i;
                currentSub = new HashSet<>();
                currentSub.add(c);
            } else {
                // continue old window
                currentSub.add(c);
            }
        }
        return longestSubR - longestSubL + 1;
    }
}