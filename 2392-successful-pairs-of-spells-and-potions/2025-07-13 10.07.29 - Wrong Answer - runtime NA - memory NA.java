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
            pairs[j++] = binSearch(success, potions, s);
        }
        return pairs;
    }

    int binSearch(long key, int[] pot, int s) {
        if ((long)pot[0] * (long)s > key) return pot.length;
        if (pot.length > 1 && (long)pot[1] * (long)s > key) return pot.length - 1;
        int l = 0, r = pot.length;
        while (l < r && r > 0 && l < pot.length) {
            int mid = l + (r-l) / 2;
            long check = (long)pot[mid] * (long)s;
            if (check == key) {
                if (check < key) return pot.length - mid;
                else r = mid;
            }
            else if (mid != 0 && ((long)pot[mid - 1] * (long)s) < key && check > key) return pot.length - mid;
            else if (check < key) l = mid + 1;
            else r = mid - 1;
        }
        return pot.length - l;
    }
}