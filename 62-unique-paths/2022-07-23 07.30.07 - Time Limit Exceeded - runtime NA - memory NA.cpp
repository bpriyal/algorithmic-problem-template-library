class Solution {
    int result;
    void util(int m, int n, int i, int j) {
        if (i >= m || j >= n) return;
        
        if (i == m - 1 && j == n - 1) ++result;
        
        util(m, n, i + 1, j);
        util(m, n, i, j + 1);
    }
public:
    int uniquePaths(int m, int n) {
        result = 0;
        
        util(m, n, 0, 0);
        
        return result;
    }
};