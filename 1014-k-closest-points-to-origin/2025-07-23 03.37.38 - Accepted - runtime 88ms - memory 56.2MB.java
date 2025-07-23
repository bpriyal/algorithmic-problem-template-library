class Solution {
    public int[][] kClosest(int[][] points, int k) {
        Map<Long, List<List<Integer>>> distToPoints = new TreeMap();
        Map<Integer, Long> pointToSq = new HashMap();
        for (int[] pair: points) {
            long x2 = pointToSq.computeIfAbsent(pair[0], key -> 1L*(pair[0]*pair[0]));
            long y2 = pointToSq.computeIfAbsent(pair[1], key -> 1L*(pair[1]*pair[1]));
            long dist = x2 + y2;
            distToPoints.computeIfAbsent(dist, x -> new ArrayList()).add(Arrays.asList(pair[0], pair[1]));
        }
        int[][] result = new int[k][2];
        int remaining = k - 1;
        while (remaining >= 0) {
            for (long dist : distToPoints.keySet()) {
                List<List<Integer>> pointsList = distToPoints.get(dist);
                // int n = pointsList.size();
                for (List<Integer> pair : pointsList) {
                    if (remaining < 0) break;
                    result[remaining][0] = pair.get(0);
                    result[remaining][1] = pair.get(1);
                    remaining--;
                }
            }
        }  
        return result;
    }

}