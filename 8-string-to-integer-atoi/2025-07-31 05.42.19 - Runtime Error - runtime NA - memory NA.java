class Solution {
    public int myAtoi(String s) {
        if (s == null || s.length() == 0) return 0;
        int n = s.length();
        StringBuilder sb = new StringBuilder();
        char[] carr = s.toCharArray();
        int i = 0;
        while(i + 1 < n && carr[i] == ' '){i++;}
        if(carr[i] == '-' || carr[i] == '+') { if (i + 1 >= n) return 0; sb.append(carr[i++]);}
        while(i + 1 < n && carr[i] == '0') {i++;}
        if(!Character.isDigit(carr[i])) return 0;
        else {
            while (i < n && Character.isDigit(carr[i])) sb.append(carr[i++]);
        }
        n = sb.length();
        int sign = 1;
        if (sb.charAt(0) == '-') {sign = -1; n--;}
        else if (sb.charAt(0) == '+') n--;
        if (n > 10) if (sign == -1) return Integer.MIN_VALUE; else return Integer.MAX_VALUE;
        if (n == 10) return getNum(sb.toString());
        System.out.println(Integer.MAX_VALUE);
        return Integer.parseInt(sb.toString());
    }

    int getNum(String s) {
        // int number = 0;
        int j = 0;
        String min = String.valueOf(Integer.MIN_VALUE);
        String max = String.valueOf(Integer.MAX_VALUE);
        if (s.charAt(0) == '-') {
            j = 1;
            while ((int)s.charAt(j) <= (int)min.charAt(j)) {j++;}
            if (j >= 10) return Integer.parseInt(s);
            else return Integer.MIN_VALUE;
        }
        else {
            while ((int)s.charAt(j) <= (int)max.charAt(j)) {j++;}
            if (j >= 10) return Integer.parseInt(s);
            else return Integer.MAX_VALUE;
        }
    }
}