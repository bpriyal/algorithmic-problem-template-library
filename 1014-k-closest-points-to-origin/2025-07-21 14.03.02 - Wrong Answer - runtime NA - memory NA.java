class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int num = k;
        Queue<Long> q = new PriorityQueue(Collections.reverseOrder());
        int i = 0;
        for (int[] p : points) {
            if (k < 1) {
                q.poll();
            }
            long val = p[0]*p[0] + p[1]*p[1];
            val = (val * 10000) + i;
            q.offer(val);
            k--;
            i++;
        }
        int[][] result = new int[num][2];
        i = 0;
        for (long val : q) {
            int ind = (int)(val % 1000);
            result[i][0] = points[ind][0];
            result[i][1] = points[ind][1];
            i++;
        }
        return result;
    }
}