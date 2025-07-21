class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = 0;
        int k = 0;
        int n1 = nums1.length;
        int j = m;

        while (j < n1 && i < n1 && k < n) {
            System.out.println(nums2[k]);
            System.out.println(nums1[i]);
            if (nums1[i] == 0) break;
            if (nums1[i] <= nums2[k]) i++;
            else {
                nums1[j] = nums1[i];
                nums1[i] = nums2[k];
                j++;
                k++;
                i++;
            }
        }
        while (j < n1 && k < n) {
            nums1[j++] = nums2[k++];
        }

    }
}

// 1 3 4 0 0 0
// 2 3 5

// 1 2 4 3 0 0
// 3 5

// 1 2 3 3 4 0
// 5
