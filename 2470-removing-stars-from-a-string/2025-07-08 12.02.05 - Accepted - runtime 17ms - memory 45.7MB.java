class Solution {
    public String removeStars(String s) {
        int n = s.length();
        char[] clean = new char[n];
        int cind = -1;
        for(char c : s.toCharArray()){
            if (c == '*' && cind != -1) {
                clean[cind--] = ' ';
            } else {
                clean[++cind] = c;
            }
        }
        String st = String.valueOf(clean);
        return st.trim();
    }
}