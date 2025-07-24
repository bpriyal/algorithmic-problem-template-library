class Solution {
    int maxInd;
    public int[] findBuildings(int[] heights) {
        if (heights == null) return null;
        int n = heights.length;
        if (n < 2) return new int[]{0};
        int count = 1;
        maxInd = n - 1;
        List<Integer> arr = new LinkedList();
        arr.add(n - 1);
        for (int i = n - 2; i >= 0; --i) {
            if (heights[i] > heights[maxInd]) {
                maxInd = i;
                arr.addFirst(i);
            }
        }
        int ret[] = new int[arr.size()];
        int j = 0;
        for (int i : arr) ret[j++] = i;
        return ret;
    }
}