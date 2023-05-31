class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int canBePlanted = 0;
        int len = flowerbed.length;

        for(int i = 0; i < len - 1; ++i){
            if(/*flowerbed[i] == 1 &&*/ flowerbed[i+1] == 0){
                int contiguousZeroes = 0;
                int addCornerSupport = 0;
                if(flowerbed[i] == 0){
                    addCornerSupport = 1;
                }
                for(int j = i; flowerbed[j] == 0; ++j, ++i){
                    if(flowerbed[j] == 0){
                        ++contiguousZeroes;
                    }                    
                }
                canBePlanted += (contiguousZeroes - 1 + addCornerSupport)/2;
                if(canBePlanted >= n){
                    return true;
                } 
            }    
        }

        if(canBePlanted >= n){
            return true;
        }
        return false;
    }
}

/*
1 - 3. 2
2 - 5. 3
3 - 7. 4
2n+1 no of zeroes required
*/