class Solution {
    public String longestCommonPrefix(String[] strs) {
        
        String common = strs[0];
        for (String s : strs) {
             if(s.length() == 0 || s == null) return "";
             for (int i = 0; i < strs.length; ++i) {
                if (!(s.charAt(i) == common.charAt(i))) {
                    if(i == 0) return "";
                    common = common.substring(0,i);
                    break;
                }
            }
        }
        return common;
       
        
    }

}