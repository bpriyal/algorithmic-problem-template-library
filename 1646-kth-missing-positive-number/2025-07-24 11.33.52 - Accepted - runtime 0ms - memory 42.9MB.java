class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n = arr.length;
        int a = 0;
        int num = 1;
        int store = 0;
        while (k > 0 && a < n) {
            if (arr[a] != num) {
                k--;
                store = num;
            } else {
                a++;
            }
            num++;
        }
        while (k > 0) {
            num++;
            k--;
        }
        store = num - 1;
        return store;
    }
}