class Solution {
    public boolean isSubsequence(String s, String t) {
        
        for(int i = 0; i < t.length();){
            
            for(; j < s.length();){
                if(i < t.length() && s.charAt(j) == t.charAt(i)){
                    j++;
                }
                i++;
            }
            return j == s.length();
        }
    }
}