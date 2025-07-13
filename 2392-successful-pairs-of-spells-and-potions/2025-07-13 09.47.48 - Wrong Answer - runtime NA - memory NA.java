class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int slen = spells.length;
        int plen = potions.length;
        if (slen == 0) return null;
        if (plen == 0) return new int[slen];
        Arrays.sort(potions);
        int[] pairs = new int[slen];
        int j = 0;
        for (int s : spells) {
            int[] pot = new int[plen];
            pot = Arrays.copyOf(potions, plen);
            for (int i = 0; i < plen; ++i) pot[i] *= s;
            // if (pot[0] > success) {
            //     pairs[j++] = plen;
            //     continue;
            // }
            // if (pot[plen - 1] < success) {
            //     pairs[j++] = 0;
            //     continue;
            // }
            pairs[j++] = binSearch(success, pot);
        }
        return pairs;
    }

    int binSearch(long key, int[] pot) {
        int l = 0, r = pot.length;
        while (l < r && r > 0 && l < pot.length) {
            int mid = l + (r-l) / 2;
            if (pot[mid] == key) {
                if (pot[mid - 1] < key) return pot.length - mid;
                else r = mid;
            }
            else if (mid != 0 && pot[mid - 1] < key && pot[mid] > key) return pot.length - mid;
            else if (pot[mid] < key) l = mid + 1;
            else r = mid - 1;
        }
        return pot.length - l;
    }
}