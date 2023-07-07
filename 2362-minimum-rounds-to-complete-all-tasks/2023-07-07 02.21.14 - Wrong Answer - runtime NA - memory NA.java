class Solution {
    public int minimumRounds(int[] tasks) {
        int totalGroups = 0;
        Map<Integer,Integer> difficultyToFreq = new HashMap<>();

        for (int i : tasks) {
            difficultyToFreq.put (i, difficultyToFreq.getOrDefault(i,0) + 1);
        }

        for (int val : difficultyToFreq.values()) {
            totalGroups += val/3;
            int mod = val % 3;
            if (mod == 1) {
                return -1;
            } else if (mod == 2) {
                ++totalGroups;
            }
        }
        return totalGroups;
    }
}

/*

/3 --> no of groups in 3 = total group +

%3 == 
    0 --> grouped into 3
    1 --> cant be grouped retrun -1
    2 --> can be grouped to 2 (+1 group)

*/