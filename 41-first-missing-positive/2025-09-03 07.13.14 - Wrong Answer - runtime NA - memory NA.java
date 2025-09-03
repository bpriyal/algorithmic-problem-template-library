class Solution {
    public int firstMissingPositive(int[] nums) {
        int currLeast = Integer.MAX_VALUE;
        int right = -1;
        for (int i : nums) {
            if (i > 0) {
                if (i == currLeast - 1) {
                    if (right == -1) right = currLeast;
                    currLeast--;
                } else if (i == currLeast + 1) {
                    if (right == -1) right = currLeast + 1;
                    // else right is already set further right
                } else if (i < currLeast) {
                    currLeast = i;
                    right = -1;
                }
            }
        }
        if (currLeast > 1) return 1;
        else if (right != -1) return right + 1;
        else return currLeast + 1;
    }
}