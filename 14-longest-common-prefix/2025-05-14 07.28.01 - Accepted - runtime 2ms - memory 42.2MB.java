class Solution {
    public String longestCommonPrefix(String[] strs) {
        String common = strs[0];

        for (String s : strs) {

            if (s == "" || s == null) return "";
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < Math.min(s.length(), common.length()); ++i) {
                if (s.charAt(i) == common.charAt(i)) {
                    sb.append(s.charAt(i));
                }
                else {
                    break;
                }
            }
            common = sb.toString();
        }
        return common;
    }
}