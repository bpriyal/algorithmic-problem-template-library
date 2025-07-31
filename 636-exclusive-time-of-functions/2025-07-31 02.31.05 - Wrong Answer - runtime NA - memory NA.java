class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
       int[] count = new int[n];
       int prevId = 0;
       int prevSTime = 0;
       int startRem = 0;
       for (int i = 0; i < logs.size(); ++i) {
            String[] curr = logs.get(i).split(":");
            int currId = Integer.parseInt(curr[0]);
            int currTime = Integer.parseInt(curr[2]);
            if (curr[1].charAt(0) == 's') {
                if (startRem > 0) {        
                    count[prevId] += currTime - prevSTime;
                }
                startRem++;
                prevId = currId;
                prevSTime = currTime;
            } else { //'end'
                startRem--;
                count[prevId] += currTime - prevSTime + 1;
                if (startRem > 0) {
                    prevSTime = currTime + 1;
                    if (i < logs.size() - 1) prevId = Integer.parseInt(logs.get(i + 1).split(":")[0]);
                }
            }
       }
       return count;
    }
}