class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        int n = costs.length;
        int l = 0;
        int r = n - 1;
        Queue<Integer> minHeap = new PriorityQueue();
        int roundsLeft = k;
        int totalCost = 0;

        if (candidates > n/2) {
            for (int c : costs) minHeap.offer(c);
            while (roundsLeft-- > 0) totalCost += minHeap.poll();
            return totalCost;
        }
        
        // System.out.println(l);
        // System.out.println(r);

        for (int i = 0; i < candidates; ++i) minHeap.offer(costs[l++]);
        for (int i = n - 1; i > n - candidates; --i) minHeap.offer(costs[r--]);

        // System.out.println(l);
        // System.out.println(r);
        
        while (roundsLeft-- > 0 && l < r) {
            totalCost += minHeap.poll(); 
            if (l < n && r >= 0 && costs[l] < costs[r]) {
                minHeap.offer(costs[l++]);
            } else if (l < n && r >= 0){
                minHeap.offer(costs[r++]);
            }
        }

        return totalCost;
    }
}