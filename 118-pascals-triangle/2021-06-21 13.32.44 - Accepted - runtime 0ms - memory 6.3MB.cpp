class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        
        for(int i = 1;i <= numRows;++i) {
            vector<int> temp(i,1);
            
            if (i > 2) {
                for(int j = 1;j < i-1;++j) {
                    //cout<<"i:"<<i<<"j:"<<j<<"val:"<<result[i-2][j]<<endl;
                    temp[j] = result[i-2][j] + result[i-2][j-1];
                    //cout<<temp[j]<<endl;
                }
            }
            
            result.push_back(temp);
        }
        
        return result;
    }
};