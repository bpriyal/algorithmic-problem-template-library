class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,int> drop;
        unordered_map<int,int> pickup;
        int size = trips.size();
        for(auto trip:trips) {
            drop[trip[2]] += trip[0];
            pickup[trip[1]] += trip[0];
        }
        
        sort(trips.begin(),trips.end(),[](vector<int> &a,vector<int> &b) {
           return a[1] < b[1]; 
        });
        
        int a = trips[0][1];
        int b = trips[size-1][1];
        
        for(int i = a;i<=b;++i) {
            capacity += drop[i] - pickup[i];
            if (capacity < 0) {
                return false;
            }
        }
        
        return true;
    }
};