class Solution {
    public int[] countBits(int n) {
        int[] bits = new int[n + 1];
        bits[0] = 0;
        if (n == 0) return bits;
        bits[1] = 1;
        if (n == 1) return bits;
        int count = 2;
        int j = 2;
        while (j < n + 1 && count < n + 1) {  
            for (int i = 0; i < count && j < n + 1;) {
                bits[j++] = bits[i] + 1;
                ++i;
            }
            count = j;
        }

        return bits;
    }
}

// 0 
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7