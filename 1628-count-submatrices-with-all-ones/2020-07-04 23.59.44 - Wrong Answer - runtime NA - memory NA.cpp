class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> cache(rows);
        for(int i = 0;i<rows;++i) {
            cache[i] = vector<int>(cols+1);
        }
        for(int i =0;i<rows;++i) {
            for(int j=cols-1;j>=0;--j) {
                if (mat[i][j] == 1) {
                    cache[i][j] = cache[i][j]+1;
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
                while(!s.empty() && s.top().first>cache[i][j]) {
                    runningsum = runningsum - (s.top().second+1)*(s.top().first-cache[i][j]);
                    n = n+s.top().second+1;
                    s.pop();
                }
                //cout<<"here3"<<endl;
                runningsum += cache[i][j];
                //cout<<runningsum<<endl;
                result += runningsum;
                //cout<<result<<endl;
                s.push(make_pair(cache[i][j],n));
            }
        }
        return result;
    }
};