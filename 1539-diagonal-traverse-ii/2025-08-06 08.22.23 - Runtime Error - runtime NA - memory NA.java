class Solution {
    List<Integer> result = new ArrayList();
    int count = 0;
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        count = nums.size();
        diag (nums, 0, 0, 0, 0);
        int[] finalRes = new int[result.size()];
        for (int i = 0; i < result.size(); ++i) finalRes[i] = result.get(i);
        return finalRes;
    }

    void diag (List<List<Integer>> nums, int i, int j, int lastI, int lastJ) {
        if (count == 0) return;
        List<Integer> copy = result;
        int c = count;
        if (i >=0 && i < nums.size() && j >= 0 && j < nums.get(i).size() && nums.get(i) != null && nums.get(i).get(j) != null) {
            int ni = nums.size();
            int nj = nums.get(i).size();
            result.add(nums.get(i).get(j));
            if (j == nj - 1) {
                count--;
            }
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
          else {
            int nj = nums.get(i).size();
            // if (i == ni - 1 && j == nj - 1) {
            //     result.add(nums.get(i).get(j));
            //     return;
            // }
            if (j > nj - 1) {
                i--; j++;
            }
            else if (j < 0) {
                j = 0;
            }
          }     
        }      
        diag(nums, i, j, lastI, lastJ);
        return;
    }
}

// 1 2 3
// 1 2 3 4 5 7 3
// 1 2
// 1 
// 1 2 3