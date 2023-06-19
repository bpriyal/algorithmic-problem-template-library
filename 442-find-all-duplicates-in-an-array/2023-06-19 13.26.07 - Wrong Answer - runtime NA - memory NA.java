class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        String arrString = Arrays.toString(nums);
        Set<Integer> dupes = new HashSet<>();
        for (int i : nums) {
            System.out.println(i);
            String c = Integer.toString(i);
            if (arrString.indexOf(c) != arrString.lastIndexOf(c)){
                dupes.add(i);
            }
        }
        return List.copyOf(dupes);
    }
}