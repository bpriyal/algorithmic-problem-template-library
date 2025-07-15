class Solution {
    public int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        List<Integer> tri = new ArrayList(Arrays.asList(1, 1, 2));
        int currSum = 4;
        int currN = 3;
         
        findTrib(n, tri, currSum, currN);
        return tri.get(2);
    }

    void findTrib (int n, List<Integer> tri, int currSum, int currN) {
        if (n == currN) return;
        int remove = tri.get(0);
        tri.remove(0);
        tri.add(currSum);
        currSum = currSum - remove + currSum;
        findTrib (n, tri, currSum, currN + 1);
        
    }

}