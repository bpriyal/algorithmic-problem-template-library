class Solution {

    public int climbStairs(int n) {
        int end = n/2;
        int total = 0;
        int i = 0;
        for (; i <= end; ++i) {
            int add = calculate(n - (i * 2), i);
            total += add;
        }
        return total; 
    }

    int calculate (int total1s, int total2s) {
        int total = total1s + total2s;
        return fact(total)/(fact(total1s) * fact(total2s));
    }

    int fact (int n) {
        if (n == 0) {
            return 1;
        } else {
            return n * fact(n - 1);
        }
    }

}