class Solution {
    vector<int> gridPoints = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> skip;
    
    bool isJumpValid(const vector<bool>& visited, int currentPoint, int targetPoint) {
        return !visited[targetPoint] && (skip[currentPoint][targetPoint] == 0 || visited[skip[currentPoint][targetPoint]]);
    }

    int util(int elements, int currentPoint, vector<bool>& visited) {
        if (elements < 0) return 0;
        if (elements == 0) return 1;

        visited[currentPoint] = true;
        int result = 0;

        for (int point : gridPoints) {
            if (isJumpValid(visited, currentPoint, point)) {
                cout<<"Valid jump:"<<currentPoint<<","<<point<<endl;
                result += util(elements - 1, point, visited);
            }
        }
        
        visited[currentPoint] = false;
        cout<<result<<endl;
        return result;
    }
public:
    int numberOfPatterns(int m, int n) {
        int result = 0;
        vector<bool> visited(10, false);
        gridPoints = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        skip.resize(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
         for (int i = m; i <= n; ++i) { 
            result += util(i - 1, 1, visited) * 4;
            result += util(i - 1, 2, visited) * 4;
            result += util(i - 1, 5, visited);
            cout<<"result: "<<result<<endl;
         }

         return result;
    }
};