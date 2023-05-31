class Solution {
    public boolean isSubsequence(String s, String t) {
        int j = 0;
        int i = 0;
        // for(int i = 0; i < t.length();){
            // for(; j < s.length();){
        while(i < t.length() && j < s.length()){
            if(s.charAt(j) == t.charAt(i)){
                j++;
            }
            i++;
        }
        return j == s.length();
    }
}