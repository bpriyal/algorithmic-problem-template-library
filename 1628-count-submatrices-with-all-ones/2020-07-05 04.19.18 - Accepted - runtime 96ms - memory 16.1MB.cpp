class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> cache(rows);
        for(int i = 0;i<rows;++i) {
            cache[i] = vector<int>(cols);
        }
        for(int i = 0;i<rows;++i) {
            cache[i][cols-1] = mat[i][cols-1]; 
        }
        for(int i =0;i<rows;++i) {
            for(int j=cols-2;j>=0;--j) {
                if (mat[i][j] == 1) {
                    cache[i][j] = cache[i][j+1]+1;
                }
            }
        }
        //cout<<"here"<<endl;
        int result = 0;
        for(int i=0;i<cols;++i) {
            stack<pair<int,int>> s;
            int runningsum = 0;
            for(int j = rows-1;j>=0;--j) {
                int n=0;
                while(!s.empty() && s.top().first>cache[j][i]) {
                    runningsum = runningsum - (s.top().second+1)*(s.top().first-cache[j][i]);
                    n = n+s.top().second+1;
                    s.pop();
                }
                //cout<<"here3"<<endl;
                runningsum += cache[j][i];
                //cout<<runningsum<<endl;
                result += runningsum;
                //cout<<result<<endl;
                s.push(make_pair(cache[j][i],n));
            }
        }
        return result;
    }
};