class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal(rowIndex+1);
        int size = 1;
        for(int i = 0;i<=rowIndex;++i) {
            pascal[i].resize(size,1);
            ++size;
        }
        //cout<<"here"<<endl;
        for(int i = 2;i<=rowIndex;++i) {
            for(int j = 1;j<pascal[i].size()-1;++j) {
                //cout<<"here1"<<endl;
                pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
            }
        }
        return pascal[rowIndex];
    }
};