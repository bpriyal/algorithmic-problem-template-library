class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList();
        int start = 1;
        backtrack (n, 0, new TreeSet(), result, k, start);
        return result;
    }

    void backtrack (int totalSum, int currSum, TreeSet<Integer> tempList, List<List<Integer>> result, int len, int start) {
        for (int i = start; i < 10; ++i) {
            if (tempList.size() > len) continue;
            if (tempList.size() == len && currSum == totalSum) {
                result.add(new ArrayList(tempList));
                return;
            }
            if (tempList.contains(i)) {
                continue;
            }
            if (i <= totalSum && currSum + i <= totalSum) {
                tempList.add(i);
                start = i + 1;
                backtrack (totalSum, currSum + i, tempList, result, len, start);
                tempList.pollLast();
                start = i - 1;
            } else if (!tempList.isEmpty()){
                return;
            }
        }
    }
}

// 1
// 1 1
// 1 1 1
// 1 1
// 1 