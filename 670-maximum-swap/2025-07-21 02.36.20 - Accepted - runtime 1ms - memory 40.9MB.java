class Solution {
    public int maximumSwap(int number) {
        int num = number;
        if (num == 0) return 0;
        int digs = 0;
        while(num >= 1) {
            num /= 10;
            digs++;
        }
        num = number;
        Integer[] arr = new Integer[digs];
        for (int i = digs - 1; i >= 0; --i) {
            arr[i] = num % 10;
            num = num / 10;
        }
        Integer[] copy = Arrays.copyOf(arr, digs);

        Arrays.sort(copy, Collections.reverseOrder());
       
        int temp = -1;
        int n = 0;
        int i;
        for (i = 0; i < digs; ++i) {
            if (arr[i] != copy[i]) {
                temp = arr[i];
                arr[i] = copy[i];
                break;
            } 
            n = n + arr[i];
            n *= 10;
        }
        for (int j = digs - 1; j > i; --j) {
            if (arr[j] == arr[i]) {
                arr[j] = temp;
                break;
            }
        }
         n = 0;
        for (int j = 0; j < digs; ++j) {
            n = n + arr[j];
            n *= 10;
        }
        return n / 10;
    }
}