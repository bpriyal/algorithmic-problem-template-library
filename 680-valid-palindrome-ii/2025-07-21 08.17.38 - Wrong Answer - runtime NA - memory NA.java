class Solution {
    public boolean validPalindrome(String s) {
        int n = s.length();
        int l = 0;
        int r = n - 1;
        char[] arr = s.toCharArray();
        boolean threshold = false;

        for (int i = 0, j = n - 1; i <= j; ) {
            
            if (arr[i] == arr[j]) {
                i++;
                j--;
            } else {
                if (threshold == true) return false;
                if (arr[i] == arr[j - 1]) {
                    threshold = true;
                    i++;
                    j = j - 2;
                } else if (arr[j] == arr[i + 1]){
                    threshold = true;
                    j--;
                    i = i + 2;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}