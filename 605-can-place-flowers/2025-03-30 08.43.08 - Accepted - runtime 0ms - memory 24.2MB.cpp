class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int size = flowerbed.size();
       int possibleLocations = 0;

       for (int i = 0; i < size; ++i) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] != 1) && (i == size - 1 || flowerbed[i + 1] != 1)) {
          flowerbed[i] = 1;
          --n;
          ++i;
        }
       }
       return n <= 0;
    }
};