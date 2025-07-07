class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet();
        Set<Integer> set2 = new HashSet();
        // List<Integer> list1 = new ArrayList();
        // List<Integer> list2 = new ArrayList();
        for (int i : nums1) {
            set1.add(i);
        }
        for(int i : nums2) {
            set2.add(i);
        }

        Set<Integer> diff1 = new HashSet(set1);
        diff1.removeAll(set2);

        Set<Integer> diff2 = new HashSet(set2);
        diff2.removeAll(set1);

        List<List<Integer>> returnList = new ArrayList();
        returnList.add(new ArrayList(diff1));
        returnList.add(new ArrayList(diff2));

        return returnList;

    }
}