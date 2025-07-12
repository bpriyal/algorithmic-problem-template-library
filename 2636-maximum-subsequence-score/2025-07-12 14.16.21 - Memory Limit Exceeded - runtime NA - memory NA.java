class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        long MAX = Integer.MIN_VALUE;
        int n = nums1.length;
        List<List<Integer>> indices = new ArrayList<>();
        indCombinations (0, n, k, new ArrayList<Integer>(), indices);

        for (List<Integer> row : indices) {
            MAX = Math.max(MAX, getSum(nums1, row) * getMin(nums2, row));
        }
        //find combinations of indices --> int[][]
        // iterate over that int[][] --> for every int[]
            //getSum of those vals in nums1 at those indices
            //getMin from nums2
            //sum*min --> check max and update
        return MAX;
    }

    void indCombinations (int start, int n, int k, List<Integer> curr, List<List<Integer>> result) {
        if (k == 0) {
            result.add(new ArrayList(curr));
            return;
        }
        for (int i = start; i < n; ++i) {
            curr.add(i);
            indCombinations (i + 1, n, k - 1, curr, result);
            curr.removeLast();
        }
    }

    long getSum (int[] nums1, List<Integer> inds) {
        long sum = 0;
        for (int i : inds) sum += nums1[i];
        return sum;
    }

    int getMin (int[] nums2, List<Integer> inds) {
        int MIN = Integer.MAX_VALUE;
        for (int i : inds) MIN = Math.min(MIN, nums2[i]);
        return MIN;
    }
}