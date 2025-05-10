class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int[] station = new int[n];
        int total = 0;

        //calculate gain at each station and now work only on this data structure
        for (int i = 0; i < n; ++i) {
            station = gas[i] - cost[i];
            total += station;
        }
        //no possibility of finding any solution if total cost is > total available gas
        if (total < 0) return -1;
        
        //Now we have 1 unique solution
        //make groups where start with 1st positive gain and go until the last negative gain
        //calculate valid start points
        //valid start points are those 
        //group on index from start to end and calculate running sum
        //
        Map<Integer, Integer> startToTotal = new Hashmap<>();
        List<Integer> validStartInd = new ArrayList<>();
        int run = 0;

        for (int i = 0; i < n; ++i) {
            boolean possible = false;
            int validStart = -1;
            int validEnd = -1;

            if (!possible && station[i] > 0 && station[i-1] < 0) {
                possible = true;
                run = 0;
                validStart = i;
            }

            run += station[i];

            if (run < 0) {
                possible = false;
                if (station[i+1] > 0) {
                    startToTotal.put(validStart, run);
                    run = 0;
                    validStart = i+1;
                }
            }

            if(possible && station > 0 )
        }

        // Map<Group, Integer> groupToTotal = new Hashmap<>();
        in loop from valid start ind to next validstartind - 1
        station[validStartInd.get(i)]

    }
}

final class Group {
    int startInd;
    int endInd;
    public Group(int s, int e) {
        this.startInd = s;
        this.endInd = e;
    }
}

-2
-2
-2
3
3

3 6 4 2 0


-1
-1
1

1 0 -1
-1



3+3 = 6


-2 
-4
-3
1 -> valid, 1,6,4,3,-1 break
5 -> we dont start here
-2
-1
-4
4 -> valid, 4, 9, 12, 10, 6, 3, 4, 9, 7, 6, 2
5 
3 

