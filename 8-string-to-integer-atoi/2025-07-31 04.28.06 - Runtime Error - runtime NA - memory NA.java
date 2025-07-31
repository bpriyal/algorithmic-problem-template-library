class Solution {
    public int myAtoi(String s) {
        int n = s.length();
        StringBuilder sb = new StringBuilder();
        char[] carr = s.toCharArray();
        int i = 0;
        while(i + 1 < n && carr[i] == ' '){i++;}
        if(carr[i] == '-' || carr[i] == '+') sb.append(carr[i++]);
        while(i + 1 < n && carr[i] == '0') {i++;}
        if(!Character.isDigit(carr[i])) return 0;
        else {
            while (i < n && Character.isDigit(carr[i])) sb.append(carr[i++]);
        }
        return Integer.parseInt(sb.toString());
    }
}