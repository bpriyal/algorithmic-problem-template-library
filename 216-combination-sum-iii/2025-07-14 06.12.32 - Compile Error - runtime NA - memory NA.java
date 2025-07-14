class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList();
        util (k, n, 0, new ArrayList(), result, 1);
        return result;
    }

    void util (int size, int sum, int currSum, List<Integer> currList, List<List<Integer>> result, int start) {
        int currSize = currList.size();
        for (int i = start; i < 11; ) {
            if (currSize == size && currSum == sum) {
                result.add(new ArrayList(currList));
                currList.removeLast();
                return;
            }
            if (i > sum) return;
            if (currSum + i > sum) return;
            if (currSum + i <= sum) {
                currList.add(i);
                util (size, sum, currSum + i, currList, result, start + 1);
                if (currList.size() > 0) currList.removeLast();
                // util (size, sum, currSum, currList, result, start + 1);
                // currList.removeLast();
            }
            if (!currList.isEmpty()) i = currlist.get(currList.size() - 1);
        }
    }
}