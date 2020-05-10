#include<algorithm> 
class Solution {
public:
    bool util(const vector<bool>& hasApple,const vector<vector<int>>& edges,int& n,int &count,const int& root,const int& rows) {
        bool ret = false;
        
        for (int i = 0;i<rows;++i) {
            if (edges[i][0] == root) {
                ++count;
                bool b = util(hasApple,edges,n,count,edges[i][1],rows);
                if (b) {
                    ++count;
                    ret = true;
                } else {
                    --count;
                }
            }
        }
        if (ret == false) return hasApple[root];
        else return true;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int rows = edges.size();
        int count = 0;
        util(hasApple,edges,n,count,0,rows);
        return count;
    }
};