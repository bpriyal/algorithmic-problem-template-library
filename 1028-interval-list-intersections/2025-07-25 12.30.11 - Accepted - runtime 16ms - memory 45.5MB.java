class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<List<Integer>> ans = new ArrayList();
        for (int[] fpair : firstList) {
            for (int[] spair : secondList) {
                if (spair[0] >= fpair[0] && spair[0] <= fpair[1]) {
                    List<Integer> temp = new ArrayList();
                    temp.add(spair[0]);
                    temp.add(Math.min(spair[1], fpair[1]));
                    ans.add(temp);
                } else if (spair[1] >= fpair[0] && spair[1] <= fpair[1]) {
                    List<Integer> temp = new ArrayList();
                    temp.add(Math.max(fpair[0], spair[0]));
                    temp.add(spair[1]);
                    ans.add(temp);
                } else if (spair[0] < fpair[0] && spair[1] > fpair[1]) {
                    List<Integer> temp = new ArrayList();
                    temp.add(fpair[0]);
                    temp.add(fpair[1]);
                    ans.add(temp);
                } else if (spair[1] > fpair[1]) {
                    break;
                }
            }
        }

        int[][] ret = new int[ans.size()][2];
        int i = 0;
        for (List<Integer> l : ans) {
            ret[i][0] = l.get(0);
            ret[i][1] = l.get(1);
            i++;
        }
        return ret;
    }
}