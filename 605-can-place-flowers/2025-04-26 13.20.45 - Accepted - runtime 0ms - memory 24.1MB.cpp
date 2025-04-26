class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int size = flowerbed.size();
      int i = 0;
      while (i < size) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0)) {
          flowerbed[i] = 1;
          --n;
          i += 2;
        } else ++i;
      }
      return n <= 0;
    }
};