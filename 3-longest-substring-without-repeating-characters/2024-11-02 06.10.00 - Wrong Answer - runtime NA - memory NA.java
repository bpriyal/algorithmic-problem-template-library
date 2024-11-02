class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map currentSub = new HashMap<Integer, Integer>();
        int longestSubL = -1;
        int longestSubR = -2;
        int l = 0;
        int len = s.length();

        for ( int i = 0 ; i < len; ++i ) {
            char c = s.charAt(i);

            // check if you wanna close old window
            if ( currentSub.containsKey(c) ) {
            // close old window
            
                if ( (i - l) > (longestSubR - longestSubL + 1) ) { 
                    // new longest sub
                    longestSubR = i - 1;
                    longestSubL = l;
                }
                
            // start new window
                l = (int)currentSub.get(c) + 1;
            }
            // else don't close old window

            // in all cases
            currentSub.put(c, i);
        }
        if ( (len - l) > (longestSubR - longestSubL + 1) ) { 
                    // new longest sub
                    longestSubR = len - 1;
                    longestSubL = l;
        }
        return longestSubR - longestSubL + 1;
    }
}