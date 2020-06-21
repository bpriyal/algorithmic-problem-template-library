class Solution {
    int rows,cols;
    int cache[50][50][6000] = {0};
    bool util(const vector<vector<int>>& dungeon,int m,int n,int health) {
        if (m >= rows || n >= cols) return false;
        health += dungeon[m][n];
        //printf("m:%d,n:%d,health:%d\n",m,n,health);
        if (health <= 0 ) {
            //cout<<"jj"<<endl;
            return false;
        }
        if (m == rows-1 && n == cols-1) {
            //cout<<"**"<<endl;
            return true;
        }
        if (cache[m][n][health] != 0) {
            //cout<<"ooo"<<cache[m][n][health]<<endl;
            return cache[m][n][health] == 1 ? true:false;
        }
        if (util(dungeon,m,n+1,health) || util(dungeon,m+1,n,health)) {
            cache[m][n][health] = 1;
            return true;
        }
        cache[m][n][health] = 2;
        return false;
    }
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //cout<<"-------------------"<<endl;
        rows = dungeon.size();
        cols = dungeon[0].size();
        int h = 0;
        for (int i = 0;i<rows;++i) {
            for(int j = 0;j<cols;++j) {
                h += dungeon[i][j] > 0 ? 0:dungeon[i][j];
            }
        }
        int l = 1;
        h = -h;
        while(l<=h) {
            int mid = l + (h-l)/2;
            //cout<<"Mid:"<<mid<<endl;
            if (util(dungeon,0,0,mid)) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};