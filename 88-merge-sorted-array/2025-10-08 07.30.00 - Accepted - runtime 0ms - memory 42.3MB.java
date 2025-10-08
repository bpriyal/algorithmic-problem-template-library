class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p = m - 1;
        int q = n - 1;
        int i = nums1.length - 1;
        for (; i >= 0 && p >= 0 && q >= 0; --i) {
            if (nums1[p] > nums2[q]) {
                nums1[i] = nums1[p--];
            } else {
                nums1[i] = nums2[q--];
            }
        }
        // while (p >= 0) {
        //     nums1[i--] = nums1[p--];
        // }
        while(q >= 0) {
            nums1[i--] = nums2[q--];
        }
    }
}