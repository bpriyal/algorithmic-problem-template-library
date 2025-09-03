class Solution {
    public int firstMissingPositive(int[] nums) {
        int currLeast = Integer.MAX_VALUE;
        int right = -1;
        int extra = -1;
        int extraRight = -1;
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
                } else {
                    if (extra == -1) {
                        extra = i;
                        extraRight = i;
                    } else if (i < extra) {
                        extra = i;
                    } else if (i == extraRight + 1){
                        extraRight++;
                    }
                }
            }
        }
        if (currLeast > 1) return 1;
        else if (right != -1) {
            if (extra == right + 1) return extraRight + 1;
            return right + 1;
        }
        else return currLeast + 1;
    }
}


// 1 2 6 3 5 4

// 2 2
// 2 3
// 2 4
