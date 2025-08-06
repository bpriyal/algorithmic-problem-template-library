class NumArray {
    int run[];
    public NumArray(int[] arr) {
        run = new int[arr.length + 1];
        run[0] = 0;
        for (int i = 1; i <= arr.length; ++i) {
            run[i] = run[i - 1] + arr[i - 1];
        }
    }
    
    public int sumRange(int left, int right) {
        return run[right + 1] - run[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */