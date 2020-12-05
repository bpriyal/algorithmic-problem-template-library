class Solution {
    int size;
    bool util(vector<int>& flowerbed,int remaining,int run) {
        if (remaining == 0) {
            return true;
        }
        if (run >= size) {
            return false;
        }
        if ((run == 0 || flowerbed[run-1] == 0) && flowerbed[run] == 0) {
            flowerbed[run] = 1;
            bool plant = util(flowerbed,remaining-1,run+1);
            flowerbed[run] = 0;
            if (plant) {
                //printf("remaining:%d||run:%d\n",remaining-1,run);
                return true;
            }
        }
        return util(flowerbed,remaining,run+1);
    }
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        size = flowerbed.size();
        return util(flowerbed,n,0);
    }
};