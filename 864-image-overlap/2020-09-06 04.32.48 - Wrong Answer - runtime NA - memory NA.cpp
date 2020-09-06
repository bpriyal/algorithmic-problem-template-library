class Solution {
    int util(vector<vector<int>>& A, vector<vector<int>>& B,int yunit,int xunit) {
        int rf=0,count=0;
        int size = A.size();
        for(int i = yunit;i<size;++i) {
            int cf = 0;
            for(int j = xunit;j<size;++j) {
                if (A[i][j] == 1 && B[rf][cf] == 1) {
                    ++count;
                }
                ++cf;
            }
            ++rf;
        }
        return count;
    }
    void cellsOne(vector<vector<int>>& X,vector<pair<int,int>> &X1s) {
        int size = X.size();
        for(int i = 0;i<size;++i) {
            for(int j = 0;j<size;++j) {
                if (X[i][j] == 1) {
                    X1s.push_back({i,j});
                }
            } 
        }
    }
public:
    struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    }
}; 
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        /* Sol 1 begins
        
        int size = A.size();
        int maxOverlap = INT_MIN;
        for(int i=0;i<size;++i) {
            for(int j = 0;j<size;++j) {
                maxOverlap = max({maxOverlap,util(A,B,i,j),util(B,A,i,j)});
            }
        }
        return maxOverlap;
        
        sol 1 ends */
        
        vector<pair<int,int>> A1s;
        vector<pair<int,int>> B1s;
        cellsOne(A,A1s);
        cellsOne(B,B1s);
        
        unordered_map<pair<int,int>,int,hash_pair> cache;
        int maxOverlap = INT_MIN;
        
        for(auto x:A1s) {
            for(auto y:B1s) {
                pair<int,int> p = {x.first-y.first,x.second-y.second};
                ++cache[p];
                maxOverlap = max(maxOverlap,cache[p]);
            }
        }
        return maxOverlap;
    }
};