class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
       int[] count = new int[n];
       Stack<Integer> jenga = new Stack();
       int prevSTime = 0;
       int startRem = 0;
       for (int i = 0; i < logs.size(); ++i) {
            String[] curr = logs.get(i).split(":");
            int currId = Integer.parseInt(curr[0]);
            int currTime = Integer.parseInt(curr[2]);
            if (curr[1].charAt(0) == 's') {
                if (startRem > 0) {        
                    count[jenga.peek()] += currTime - prevSTime;
                }
                jenga.push(currId);
                startRem++;
                // prevId = currId;
                prevSTime = currTime;
            } else { //'end'
                count[jenga.pop()] += currTime - prevSTime + 1;
                startRem--;
                if (startRem > 0) {
                    prevSTime = currTime + 1;
                    // if (i < logs.size() - 1) prevId = jenga.peek();
                }
            }
       }
       return count;
    }
}