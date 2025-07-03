class Solution {
    public String reverseWords(String s) {
        StringBuilder str = new StringBuilder();
        StringBuilder prefix = new StringBuilder();
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (s.charAt(i) == ' ') {
                if (prefix.length() != 0) {
                    if (str.length() != 0) {
                        prefix.append(" ").append(str);
                    }
                    str = prefix;
                    prefix = new StringBuilder();
                }  
            } else {
                prefix.append(s.charAt(i));
            }
        }
        if (!prefix.toString().equals("")) {
            if (str.length() != 0) prefix.append(" ").append(str);
            str = prefix;
        }
        return str.toString();
    }
}