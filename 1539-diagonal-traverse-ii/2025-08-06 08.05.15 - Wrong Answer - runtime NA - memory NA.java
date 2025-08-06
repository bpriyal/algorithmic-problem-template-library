class Solution {
    List<Integer> result = new ArrayList();
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        diag (nums, 0, 0, 0, 0);
        int[] finalRes = new int[result.size()];
        for (int i = 0; i < result.size(); ++i) finalRes[i] = result.get(i);
        return finalRes;
    }

    void diag (List<List<Integer>> nums, int i, int j, int lastI, int lastJ) {
        List<Integer> copy = result;
        if (i >=0 && i < nums.size() && j >= 0 && j < nums.get(i).size() && nums.get(i) != null && nums.get(i).get(j) != null) {
            int ni = nums.size();
            int nj = nums.get(i).size();
            result.add(nums.get(i).get(j));
            if (i == ni - 1 && j == nj - 1) return;
            if (j == 0) {
                lastI = i;
                lastJ = 0;
            } 
            // else if (lastI == nums.size() - 1) lastJ++;
            i--;
            j++;
        }

        else {
            int ni = nums.size();
            if (i < 0) {
                if (lastI == ni - 1) {
                    i = lastI;
                    j = ++lastJ;
                } else {
                    i = lastI + 1;
                    j = 0;
                }
            }
            else if (i >= nums.size() || nums.get(i) == null) i--;

            int nj = nums.get(i).size();

            if (i == ni - 1 && j == nj - 1) {
                result.add(nums.get(i).get(j));
                return;
            }

            if (j > nj - 1) {
                i--; j++;
            }

            // if (nums.get(i).get(j) == null) {
            //     i--; j++;
            // }

            if (j < 0) {
                j = 0;
            }
            
        }      
        diag(nums, i, j, lastI, lastJ);
        return;
    }
}