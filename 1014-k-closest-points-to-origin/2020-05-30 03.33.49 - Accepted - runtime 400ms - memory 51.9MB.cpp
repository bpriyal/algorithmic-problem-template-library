class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        sort(points.begin(),points.end(),[](const vector<int> &a,const vector<int> &b) -> bool{
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        });
        for (int i=0;i<K;++i) {
            result.push_back(points[i]);
        }
        return result;
    }
};