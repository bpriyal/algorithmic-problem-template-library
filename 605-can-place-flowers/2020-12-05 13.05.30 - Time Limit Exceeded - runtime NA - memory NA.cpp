class Solution {
    int size;
    vector<vector<int>> dp;
    bool util(vector<int>& flowerbed,int remaining,int run) {
        if (remaining == 0) {
            return true;
        }
        if (run >= size) {
            return false;
        }
        if (dp[run][remaining] != -1) {
            return dp[run][remaining];
        }
        dp[run][remaining] = 0;
        if ((run == 0 || flowerbed[run-1] == 0) && flowerbed[run] == 0 && (run+1 >=size || flowerbed[run+1] == 0)) {
            flowerbed[run] = 1;
            bool plant = util(flowerbed,remaining-1,run+1);
            flowerbed[run] = 0;
            if (plant) {
                dp[run][remaining] = 1;
                return true;
            }
        }
        bool notPlanted = util(flowerbed,remaining,run+1);
        if (notPlanted) {
             dp[run][remaining] = 1;
            return true;
        }
        return false;
    }
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        size = flowerbed.size();
        dp.resize(size+1,vector<int>(n+1,-1));
        return util(flowerbed,n,0);
    }
};