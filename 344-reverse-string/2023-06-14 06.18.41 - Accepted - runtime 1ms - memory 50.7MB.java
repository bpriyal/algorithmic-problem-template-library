class Solution {
    public void reverseString(char[] s) {
        int len = s.length;
        int i = 0;
        int j = len-1;
        for(; i < len && j > i; ++i, --j){
            char buffer = s[i];
            s[i] = s[j];
            s[j] = buffer;
        }
    }
}