class Solution {
    int MAX = Integer.MIN_VALUE;
    public long maxScore(int[] nums1, int[] nums2, int k) {
        helper (new ArrayList<Integer>(), 0, nums1, nums2, k);
        return MAX;
    }

    void helper (List<Integer> inds, int currI, int[] nums1, int[] nums2, int k) {
        // if (k - inds.size() > nums1.length - 1 - currI) return;
        if (inds.size() == k) {
            int val1 = 0;
            int min2 = Integer.MAX_VALUE;
            for (int i : inds) {
                val1 += nums1[i];
                min2 = Math.min(min2, nums2[i]);
            }
            MAX = Math.max(MAX, val1 * min2);
            int max = MAX;
            System.out.println(max);
            return;
        }
        for (int i = currI; i < nums1.length; ++i) {
            inds.add(i);
            helper (inds, i + 1, nums1, nums2, k);
            inds.removeLast();
        }
    }
}