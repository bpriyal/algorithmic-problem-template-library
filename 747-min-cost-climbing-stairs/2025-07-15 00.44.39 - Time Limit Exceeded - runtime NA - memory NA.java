class Solution {
    public int minCostClimbingStairs(int[] cost) {
        if (cost.length == 0) return 0;
        if (cost.length == 1) return cost[0];
        int s0 = helper (cost, 0, cost[0]);
        int s1 = helper (cost, 1, cost[1]);
        return Math.min(s0, s1);
    }
    int helper (int[] cost, int ind, int sumAtInd) {
        if (ind > cost.length - 1) return sumAtInd;
        int n1 = sumAtInd, n2 = sumAtInd;
        if (ind + 1 < cost.length)
            n1 = helper (cost, ind + 1, sumAtInd + cost[ind + 1]);
        if (ind + 2 < cost.length)
            n2 = helper (cost, ind + 2, sumAtInd + cost[ind + 2]);
        return Math.min(n1, n2);
    }
}