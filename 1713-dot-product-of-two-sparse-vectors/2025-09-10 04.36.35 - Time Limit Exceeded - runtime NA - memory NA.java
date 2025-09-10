class SparseVector {
    int[][] indNums;
    SparseVector(int[] nums) {
        indNums = new int[nums.length][2];
        int[][] copy = indNums;
        int j = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                indNums[j][0] = i;
                indNums[j][1] = nums[i];
                j++;
            }
        }
    }
    
	// Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        int[][] copythis = this.indNums;
        int total = 0;
        int i = 0;
        int j = 0;
        int n1 = this.indNums.length;
        int n2 = vec.indNums.length;
        boolean once = false;
        if (n1 == 0 || n2 == 0) return 0;
        // if (this.indNums[0][0] == 0 && vec.indNums[0][0] == 0) {
        //     total += (this.indNums[0][1] * vec.indNums[0][1]);
        //     i++; j++;
        // }
        while (i < n1 && j < n2) {
            if (this.indNums[i][0] == vec.indNums[j][0] && (once && this.indNums[i][0] > 0 || vec.indNums[j][0] > 0)) {
                total += (this.indNums[i][1] * vec.indNums[j][1]);
                i++;
                j++;
            } else {
                while ((i < n1 && j < n2) && this.indNums[i][0] < vec.indNums[j][0]) i++;
                while ((i < n1 && j < n2) && this.indNums[i][0] > vec.indNums[j][0]) j++;
            }
            once = true;
        }
        return total;
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);