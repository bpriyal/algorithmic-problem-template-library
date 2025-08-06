class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        int m = nums.size();
        int n = nums.get(0).size(); //max no?
        int nDiagRows = m;
        int i = 0;
        int nEls = 0;
        List<List<Integer>> ret = new ArrayList();
        while (i++ < nDiagRows) ret.add(new ArrayList());

        for (i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.get(i).size(); ++j) {
                while (i + j >= ret.size())
                    ret.add(new ArrayList());
                ret.get(i+j).add(nums.get(i).get(j));
                nEls++;
            }
        }
        int k = 0;
        
        int[] res = new int[nEls];
        for (i = 0; i < ret.size(); ++i) {
            for (int j = ret.get(i).size() - 1; j >= 0; --j) {
                res[k++] = ret.get(i).get(j);
            }
        }
        return res;
    }
}


