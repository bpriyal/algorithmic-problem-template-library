class Solution {
    int[] w;
    int[] prob;
    int[] count;
    int total;

    public Solution(int[] w) {
        this.w = w;
        this.prob = calcProb(w);
        this.count = new int[w.length];
        total = 0;
    }

    int[] calcProb(int[] w) {
        int total = 0;
        int[] ret = new int[w.length];
        for (int i : w) total += i;
        for (int i = 0; i < w.length; ++i) {
            ret[i] = (100 * w[i]) / total;
        }
        return ret;
    }
    
    public int pickIndex() {
        for (int i = 0; i < w.length; ++i) {
            if ((count[i] / ++total) < prob[i]) return i;
        }
        count = new int[w.length];
        total = 1;
        return 0;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

//  2 4 6 3 1

// 2/
//  16