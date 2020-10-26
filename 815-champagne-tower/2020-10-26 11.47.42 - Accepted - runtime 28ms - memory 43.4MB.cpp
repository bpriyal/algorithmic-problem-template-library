class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> cache(101,vector<double>(101,0.0));
        cache[0][0] = poured;
        for(int i = 0;i < 100;++i) {
            for(int j = 0;j <= i ;++j) {
                if (cache[i][j] > 1) {
                    //cout<<"here"<<endl;
                    cache[i+1][j] += (cache[i][j]-1)/2;
                    cache[i+1][j+1] += (cache[i][j]-1)/2;
                    cache[i][j] = 1;
                }
            }
        }
        return cache[query_row][query_glass];
    }
};