class Solution {
    public int minAddToMakeValid(String s) {
        int left = 0;
        int change = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                left++;
            } else if (c == ')'){
                if (left > 0) left--;
                else change++;
            }
        }
        change += left;
        return change;
    }
}