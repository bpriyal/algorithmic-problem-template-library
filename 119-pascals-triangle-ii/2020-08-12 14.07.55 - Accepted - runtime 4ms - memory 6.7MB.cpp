class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lastRow(rowIndex+1,1);
        for(int i = 2;i<=rowIndex;++i) {
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1;j<i;++j) {
                temp.push_back(lastRow[j-1]+lastRow[j]);
            }
            temp.push_back(1);
            lastRow = temp;
        }
        return lastRow; 
    }
};