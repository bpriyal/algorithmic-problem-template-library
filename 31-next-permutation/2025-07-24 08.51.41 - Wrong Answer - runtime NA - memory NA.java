class Solution {
    public void nextPermutation(int[] nums) {

        int changeR = nums.length - 1;
        int j = 0;

            for ( j = nums.length - 2; j >= 0; --j) {
                if (nums[j] > nums[j + 1]) {
                    changeR = j;
                }
                if (nums[j] < nums[j + 1]) {
                        int swap = nums[j];
                        nums[j] = nums[changeR];
                        nums[changeR] = swap;
                    if (j + 1 != 0) arrange(nums, j+1, 0);
                    break;
                }
            }
            if (j == -1) Arrays.sort(nums);
    }
    void arrange (int[] nums, int l, int r) {
        while (l < r) {
            int swap = nums[l];
            nums[l] = nums[r];
            nums[r] = swap;
        }
    }
}

// //1, 6, 5, 2, 4, 3

// 1 3 2

// 1 3 5 6

// 1 3 6 5

// 1 5 3 6

// 1 5 6 3

// 1 6 3 5

// 1 6 5 3

// 1 2 3 4 5 4 3


// 1 6 5 3

// 6 5 3 1
