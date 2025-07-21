class Solution {
    public boolean validPalindrome(String s) {
        int n = s.length();
        int l = 0;
        int r = n - 1;
        char[] arr = s.toCharArray();
        // boolean threshold = false;
        return helper (arr, 0, n - 1, false);
        
    }

    boolean helper (char[] arr, int l, int r, boolean threshold) {
        for (int i = l, j = r; i <= j; ) {
            if (arr[i] == arr[j]) {
                i++;
                j--;
            } else {
                if (threshold == true) return false;
                if (i == arr.length / 2 || j == arr.length / 2) return true;
                return (helper (arr, i, j - 1, true) || helper (arr, i + 1, j, true));
                // 
                // if (arr[i] == arr[j - 1]) {
                //     threshold = true;
                //     if (!helper (arr, i, j - 1, true)) return false;
                //     // i++;
                //     // j = j - 2;
                // } 
                // if (arr[j] == arr[i + 1]){
                //     threshold = true;
                //     if (!helper (arr, i + 1, j, true)) return false;
                //     // j--;
                //     // i = i + 2;
                // } else {
                //     return false;
                // }
            }
        }
        return true;
    }
}