class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int size = flowerbed.length;
        int i = 0;
        while (i < size) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                --n;
                i += 2;
            } else ++i;
            if (n == 0) return true;
        }
        return n <= 0;
    }
}