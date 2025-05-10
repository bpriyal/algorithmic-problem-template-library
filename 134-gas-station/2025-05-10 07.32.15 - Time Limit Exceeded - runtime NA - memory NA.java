class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;

        
        //in loop
        // for (int i = j; i != ; i = i%n) {
        for (int j = 0; j < n; ++j) {
            int avail = 0;
            int i = j;
            boolean incycle = false;
            do {
                avail += gas[i];
                if (avail - cost[i] < 0) {break;}
                avail -= cost[i];
                i = ++i % n;
                incycle = true;
            } while (i != j);
            if (i == j && incycle) return j;
        }

        return -1;
            
    }

}