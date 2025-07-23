class Solution {
     Map<Long, List<List<Integer>>> distToPoints = new TreeMap();
    Map<Integer, Long> pointToSq = new HashMap();

    public int[][] kClosest(int[][] points, int k) {
        // points[0][2] = 1;
        computeDistToPoints(points);
        List<Long> allDistsList = allDists(points);
        List<Long[]> allDistsIndList = new ArrayList();
        for (int i = 0; i < points.length; ++i) {
            Long[] p = new Long[2];
            p[0] = 1L * allDistsList.get(i);
            p[1] = 1L * i;
            allDistsIndList.add(i, p);
        }

        System.out.println(allDistsList);

        int[][] result = new int[k][2];
        int i = 0;

        List<Long[]> kSmallestDists = quickSelect(allDistsIndList, k);
        for (Long[] pair : kSmallestDists) {
            int ind = Integer.parseInt(pair[1].toString());
            result[i][0] = points[ind][0];
            result[i][1] = points[ind][1];
            i++;
        }
        System.out.println("list "+kSmallestDists);

        return (int[][])result;

        
        // int remaining = k - 1;
        // while (remaining >= 0) {
        //     for (long dist : distToPoints.keySet()) {
        //         List<List<Integer>> pointsList = distToPoints.get(dist);
        //         // int n = pointsList.size();
        //         for (List<Integer> pair : pointsList) {
        //             if (remaining < 0) break;
        //             result[remaining][0] = pair.get(0);
        //             result[remaining][1] = pair.get(1);
        //             remaining--;
        //         }
        //     }
        // }  
        // return result;
    }

    void computeDistToPoints (int[][] points) {
        for (int[] pair: points) {
            long dist = getDist(pair);           
            distToPoints.computeIfAbsent(dist, x -> new ArrayList()).add(Arrays.asList(pair[0], pair[1]));
        }
    }

    long getDist (int[] pair) {
        long x2 = pointToSq.computeIfAbsent(pair[0], key -> 1L*(pair[0]*pair[0]));
        long y2 = pointToSq.computeIfAbsent(pair[1], key -> 1L*(pair[1]*pair[1]));
        long dist = x2 + y2;
        return dist;
    }

    List<Long> allDists(int[][] points) {
        List<Long> allDistList = new ArrayList();
        for (int[] pair : points) allDistList.add(getDist(pair));
        return allDistList;
    }
    
    List<Long[]> quickSelect (List<Long[]> allDistsList, int k) {
        if (allDistsList.size() == 0) return allDistsList;
        if (k == allDistsList.size()) return allDistsList;

        long pivot = allDistsList.get(new Random().nextInt(allDistsList.size()))[0];
        List<Long[]> left = new ArrayList(); 
        List<Long[]> mid = new ArrayList(); 
        List<Long[]> right = new ArrayList(); 

        for (Long[] i : allDistsList) {
            if (i[0] < pivot) left.add(i);
            if (i[0] == pivot) mid.add(i);
            if (i[0] > pivot) right.add(i);
        }

        System.out.println(left);
        System.out.println(mid);
        System.out.println(right);

        if (k == left.size()) return left;
        if (k == left.size() + mid.size()) {
            left.addAll(mid);
            return left;
        }

        if (k < left.size()) {
            return quickSelect (left, k);
        } 
        if (k < left.size() + mid.size()) {
            left.addAll(quickSelect (mid, k - left.size()));
            return left;
        } 
        left.addAll(quickSelect (right, k - left.size() - mid.size()));
        left.addAll(mid);
        return left;

    }
}