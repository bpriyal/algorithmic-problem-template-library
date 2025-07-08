class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int n = arr.length;
        int MAX = 2001;
        int freqs[] = new int[MAX];
        boolean[] occurs = new boolean[MAX];
        // for (boolean o : occurs) o = false;

        for (int i : arr) {
            freqs[i + MAX/2]++;
        }

        // System.out.println(freqs[0]);

        for (int i : freqs) {
            if (i != 0) {
                if (occurs[i]) {
                    // System.out.println("repeated occurrences"+i);
                    return false;
                }
                occurs[i] = true;
                // System.out.println("set true these no of freqs occur: " + i);
            }             
        }
        return true;
    }
}