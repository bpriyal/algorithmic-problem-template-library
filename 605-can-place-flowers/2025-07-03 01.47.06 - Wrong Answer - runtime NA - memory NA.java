class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        boolean isContArr = false;
        int nz = -1;
        if (flowerbed[0] == 0) nz = 0;
        int total = 0;
        int i;
        for (i = 0; i < flowerbed.length - 1; ++i) {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                isContArr = true;
                nz++;
            }
            else if (isContArr) {
                total += (nz + 1)/2;
                nz = -1;
                isContArr = false;
            }
        }
        if (isContArr) {
            if (flowerbed[i] == 0) {
                nz++;
            }
            total += (nz + 1)/2;
        } 
        return total >= n;
    }
}

/*
0 0 0 0 0 1 1 0 0 1 0 0 0 1 0 0 0 0 0 1 1 1 1
*/
// remove 1st and last in contiguous azeroes -- except edge cases
// find max that can be placed in remaining
// check edge cases later