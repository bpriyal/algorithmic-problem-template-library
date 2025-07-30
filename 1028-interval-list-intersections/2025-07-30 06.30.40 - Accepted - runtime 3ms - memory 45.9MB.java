class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        boolean fsweep = false;
        boolean ssweep = false;
        if (secondList.length > 0 && firstList.length > 0 && secondList[0][0] < firstList[0][0]) {
            int[][] temp = firstList;
            firstList = secondList;
            secondList = temp;
        }

        int fl = firstList.length;
        int sl = secondList.length;
        if (fl == 0 || sl == 0) return new int[0][];
        
        int i = 0;
        int j = 0;
        List<int[]> res = new ArrayList<>();

        while (i < fl && j < sl) {
            int start = Math.max(firstList[i][0], secondList[j][0]);
            int end = Math.min(firstList[i][1], secondList[j][1]);

            if (start <= end) {
                res.add(new int[]{start, end});
            }

            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }

        return res.toArray(new int[res.size()][]);
    }
}