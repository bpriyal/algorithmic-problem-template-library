class Solution {
    public String licenseKeyFormatting(String s, int k) {
        s = s.replace("-","");
        int n = s.length();
        int count = 0;
        StringBuilder ans = new StringBuilder();

        for (int i = n-1; i >= 0; --i) {
            if (s.charAt(i) != '-') {
                ans.append(Character.toUpperCase(s.charAt(i)));
                count++;
                if (count == k && i != 0) {
                    ans.append('-');
                    count = 0;
                }
            }
        }
        
        ans.reverse();
        return ans.toString();

    }
}